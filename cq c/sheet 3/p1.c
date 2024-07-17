#include<stdio.h>
#include<stdlib.h>
int main ()
{
int *arr;
int n,m;
printf("enter the size for allocating the array : ");
scanf("%d",&n);
arr=(int*)malloc(n*sizeof(int));
printf("enter the elements in the array :");
for(int i=0;i<n;i++)
{
    scanf("%d",&arr[i]);
}
printf("enter the number of elements for reallocating the array : ");
scanf("%d",&m);
arr=(int *)realloc(arr,m*sizeof(int));
printf("enter the elements after reallocating:");
for(int i=0;i<m;i++)
{
    scanf("%d",&arr[i]);
}
for(int i=0;i<m;i++)
{
    printf("%d",arr[i]);
}
    return 0;
}