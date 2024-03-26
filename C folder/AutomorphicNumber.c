#include<stdio.h>
int square(int n)
{
    int res=n*n;
    res=res%10;
    return res;
}
int main ()
{
    int num,n=1,c=0;
    printf("enter the number: ");
    scanf("%d",&num);
    int org=num;
    int res=square(num);
    num=num%10;
    if(num==res)
    printf("%d is an AutomorphicNumber",org);
    else
    printf("%d is not AutomorphicNumber",org);
    return 0;
}