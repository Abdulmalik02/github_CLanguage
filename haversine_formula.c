#ifdef STANDARD
#include <stdio.h>
#include <string.h>
#ifdef __WIN__
typedef unsigned __int64 ulonglong;	
typedef __int64 longlong;
#else
typedef unsigned long long ulonglong;
typedef long long longlong;
#endif /*__WIN__*/
#else
#include <my_global.h>
#include <my_sys.h>
#endif
#include <mysql.h>
#include <m_ctype.h>
#include <m_string.h>		
#include <ctype.h>

#include <math.h>

#ifdef HAVE_DLOPEN


my_bool 
haversine_distance_init( UDF_INIT* initid, UDF_ARGS* args, char* message );

void 
haversine_distance_deinit( UDF_INIT* initid );

double 
haversine_distance( UDF_INIT* initid, UDF_ARGS* args, char* is_null, char *error );

void
str_to_lowercase( char* src );



my_bool 
haversine_distance_init( UDF_INIT* initid, UDF_ARGS* args, char* message ) {

	if ( args->arg_count < 4 ) {
		strcpy(message,"wrong number of arguments: haversine_distance() requires four arguments");
    	return 1;
  	}

  	if ( (args->arg_type[0] != REAL_RESULT) ) {
		//strcpy( message, "haversine_distance() requires real as parameters 1" ); return 1;
		args->arg_type[0] = REAL_RESULT;
  	}

  	if ( (args->arg_type[1] != REAL_RESULT) ) {
		//strcpy( message, "haversine_distance() requires real as parameters 2" ); return 1;
		args->arg_type[1] = REAL_RESULT;
  	}

  	if ( (args->arg_type[2] != REAL_RESULT) ) {
		//strcpy( message, "haversine_distance() requires real as parameters 3" ); return 1;
		args->arg_type[2] = REAL_RESULT;
  	}

  	if ( (args->arg_type[3] != REAL_RESULT) ) {
		//strcpy( message, "haversine_distance() requires real as parameters 4" ); return 1;
		args->arg_type[3] = REAL_RESULT;
  	}

  	/*
  	 * The 5th argument is the type of distance to return. It is
  	 * optional. Valid arguments are 'km', 'ft', 'mi'
  	 */
  	if ( (args->arg_type[4] != STRING_RESULT) ) {
		//strcpy( message, "haversine_distance() requires string as parameters 5" ); return 1;
		args->arg_type[4] = STRING_RESULT;
  	}

  	double *dist = malloc( sizeof(double) );
	if ( dist == NULL ) {
		strcpy(message, "haversine_distance() allocation error");
		return 1;
	}

	*dist = -1.0;

	initid->decimals 	= 6;
	initid->maybe_null	= 1;
  	initid->max_length	= 64;
	initid->ptr = (char*)dist;

	return 0;
}


void 
haversine_distance_deinit( UDF_INIT* initid ) {
	free( initid->ptr );
}


double 
haversine_distance( UDF_INIT* initid, UDF_ARGS* args, char* is_null, char *error ) {

        /*Lat/Long should not be NULL*/
        if (!args->args[0] || !args->args[1] || !args->args[2] || !args->args[3]) {
            *is_null = 1;
            return 0;
        }

	double result = *(double*) initid->ptr;
	
	/*Earth Radius in Kilometers.*/
	double R = 6372.797560856;
	
	double DEG_TO_RAD = M_PI/180.0;
	double RAD_TO_DEG = 180.0/M_PI;
  
	double lat1 = *(double*) args->args[0];
	double lon1 = *(double*) args->args[1];
	double lat2 = *(double*) args->args[2];
	double lon2 = *(double*) args->args[3];

	double dlon = (lon2 - lon1) * DEG_TO_RAD;
	double dlat = (lat2 - lat1) * DEG_TO_RAD;
	double a =  pow(sin(dlat * 0.5),2)+ cos(lat1*DEG_TO_RAD) * cos(lat2*DEG_TO_RAD) * pow(sin(dlon * 0.5),2);
	double c = 2.0 * atan2(sqrt(a), sqrt(1-a));
	
	result = ( R * c );

	/*
	 * If we have a 5th distance type argument...
	 */
	if (args->arg_count == 5) {
		str_to_lowercase(args->args[4]);

		if (strcmp(args->args[4], "ft") == 0) result *= 3280.8399;
		if (strcmp(args->args[4], "mi") == 0) result *= 0.621371192;
	}

	return result;
}


void
str_to_lowercase( char* src ) {
	for (; *src; src++) *src = tolower(*src);
}


#endif

