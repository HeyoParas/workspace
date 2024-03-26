#include <stdio.h>
int joins(int n)
{
    int sum=0,rem;
    while(n)
        {
            rem=n%10;
            sum=sum+rem;
            n=n/10;
        }
    return sum;
};
int Isprime(int num)
{
    int count=0;
    for(int i=2;i<=num;i++)
    {
        if(num%i==0)
        {
            count++;
        }
    }
    if(count==1)
    {
        return 1;
    }
    else 
    return -1;
};

int main()
{
    int num,res;
    printf("enter the number :");
    scanf("%d",&num);
    do
    {
        res=joins(num);
        num=res;
    }
    while(num>9);
    printf("the sum is :%d\n",res);
    if(Isprime(res)==1)
    {
        printf("%d is prime number",res);
    }
    if(Isprime(res)==-1)
    {
        printf("%d is not prime number",res);
    }
    return 0;
}
