#include<stdio.h>
int main ()
{
    int n,sum=0;
    printf("enter the size:");
    scanf("%d",&n);
    int arr[n];
    for(int i=1;i<=n;i++)
    {
        arr[i]=i*i;
        sum=sum+arr[i];
    }
    printf("the square natural up to %d terms are: ",n);
    for(int i=1;i<=n ;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\nthe sum of square natural number up to %d terms = %d",n,sum);

    return 0;
}