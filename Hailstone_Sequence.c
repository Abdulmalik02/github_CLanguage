/*Program to print hailstone sequence; AUTHOR:rapteon; DATE:20190223*/
//HAILSTONE SEQUENCE
/*
For a number n,
 if n is odd
  n  = 3n + 1
if n is even
  n = n / 2
This continues till n becomes one
*/

#include<stdio.h>

int main(){
  int n;

  printf("Enter the number to generate hailstone sequence: ");
  scanf("%d", &n);

  while(n > 1){
    if(n%2 == 0)
      n = n / 2;
    else
      n = (3 * n)+ 1;
    printf("%d\n", n);
  }
}
