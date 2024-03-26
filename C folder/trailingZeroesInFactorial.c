#include<stdio.h>
int main ()
{
    int num,n=1,c=0;
    printf("enter the number: ");
    scanf("%d",&num);
    for(int i=1;i<=num;i++)
    {
        n=n*i;
    }
    printf("fatorial is:%d",n);
     while (n) {
        int rem=n%10; 
        if(rem==0)
        {
             c++;
        }
        n=n/10;      
    }
    printf("\ntrailing Zeroes are: %d",c);
    return 0;
}