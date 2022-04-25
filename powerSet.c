  
//
//  main.c
//  powerset
//
//  Created by ziggytao on 17/4/8.
//
#include <stdio.h>
#define MAX 100
char value[MAX];
static int count = 0;
void show1(char arr[],int mask[],int n);
int isset(int arr[],int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        if(arr[i] == 1)
            return 1;
    }
    return 0;
}
void powerset(int arr[],int i,int n)//?i(?0?n - 1)?????????
{
    if(i == n)//n???????????(0 ? 1)
    {
        if(isset(arr, n))//??? count??
            count++;
        show1(value,arr,n);//??value ?n???????1???
        //???????????ABCDE ABCD ABCE? ??arr 11111 11110 11101
    }
    else
    {
        arr[i] = 1;//???????1
        powerset(arr, i + 1, n);//?????? ???????????arr[i]
        arr[i] = 0;//???????0 ???????
        powerset(arr, i + 1, n);//??????
    }
}
void show1(char arr[],int mask[],int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        if(mask[i] == 1)
            printf("%c",arr[i]);
    }
    printf("\t");
}
int main(int argc, const char * argv[]) {
    int n,mask[MAX],j;
    for(j = 0; j < MAX; j++)
    {
        mask[j] = 0;
        value[j] = 'A' + j;
    }
    printf("Enter a number:");
    scanf("%d",&n);
    while(n >= 0 && n <= 100)
    {
        printf("0\t");
        powerset(mask, 0, n);
        printf("\nTotal:%d\n",count + 1);
        count = 0;
        printf("Enter a number:");
        scanf("%d",&n);
    }
    return 0;
}
