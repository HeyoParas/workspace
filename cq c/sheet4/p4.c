//sum of number digit by digit
#include<stdio.h>
int fun(int n)
{
    if(n==0)
    return 0;
    else
    return n%10+fun(n/10);
}
int main ()
{
    int n;
    printf("enter the num :");
    scanf("%d",&n);
    int res=fun(n);
    printf("sum is :%d",res);
    return 0;
}