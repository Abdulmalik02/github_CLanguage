#include<stdio.h>
#include<conio.h>
#include<math.h>
//void mtrix_print(int a[3][3]);
int main()
{
    int i,j,a[3][3],k,l,b[3][3];
   printf("ENTER 3X3 MATRIX : \nI WILL TRANSPOSE IT : \n");
/*making the complete array filled with zeros to make it look symmetric*/

   for(i=0;i<3;i++)
    {
    for(j=0;j<3;j++)
        {
        a[i][j]=0;

        }
    }
/*filling the array for the matrix */
   for(i=0;i<3;i++)
    {


    for(j=0;j<3;j++)
        {

        printf("a[%d][%d] = ",i+1,j+1);
        scanf("%d",&a[i][j]);



     // matrix printer code
           for(k=0;k<3;k++)
    {
    for(l=0;l<3;l++)
        {



        printf("%6.2d\t ",a[k][l]);




            }
            printf("\n");

        }
           // mtrix_print(a[3][3]);

            printf("Hooray! u successfully Entered An Element .\n\n");

        }//j  for loop ends here



    }//i for loop ends here

    printf("\nTRANSPOSE OF MATRIX U GAVE IS \n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            b[i][j]=a[j][i];
        }
    }

    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%6.2d\t",b[i][j]);
        }
        printf("\n");
    }
   return 0;
}

/*void mtrix_print(int a[3][3])
{
    int k,l;

}*/

