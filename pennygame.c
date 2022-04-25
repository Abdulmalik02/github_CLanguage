#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char predic1[3];
char predic2[3];
int sigue=1;
int secuencia[256];
int i,j,k=1;
void jug1(){
	printf("Player 1's Guess: ");
	fgets(predic1, sizeof(3), stdin);
	getchar();
	printf(predic1,"\n");
}

void jug2(){
	while (k==1){
		printf("Player 2's Guess: ");
		fgets(predic2, sizeof(3), stdin);
		getchar();
		if (predic1==predic2){ 
			printf("Por favor seleccione una predicción distinta a la del jugador 1.\n");}
		else k=0;
	}
		printf(predic2,"\n");
}

int evaluar(int a){
	if (a==0 && secuencia[i-a]==predic1[3-a] ) {
		printf("1");
		return 1;
	}
	else if (secuencia[i-a]==predic1[3-a]) evaluar(a-1);
	else return 0;
}

int evaluar2(int a){
	if (a==0 && secuencia[i-a]==predic2[3-a] ) {
		printf("2");
		return 1;
	}
	else if (secuencia[i-a]==predic2[3-a]) evaluar(a-1);
	else return 0;
}

int main(int argc, char *argv[]) {
	
	srand(time(NULL));
	
	jug1();
	
	jug2();
	
	while (sigue==1){
		int coc=(rand()%2);
		if (coc==0) secuencia[i]='o';
		else if (coc==1) secuencia[i]='x';
		
		printf("%c", secuencia[i]);
		
		if(evaluar(3)==1) sigue=0;
		if(evaluar2(3)==1) sigue=0;
		i++;
	}
	
	
	return 0;
}

