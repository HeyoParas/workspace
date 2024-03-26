#include<stdio.h>
int main ()
{
    int num,n,c=0;
    printf("enter the number: ");
    scanf("%d",&num);
    for(int i=1;i<=num;i++)
    {
        n=i;
        while(n)
        {
        int rem=n%10; 
        if(rem==1)
        {
             c++;
        }
        n=n/10;      
        }
    }
    printf("Total number of digit 1 in the range [1,%d] :%d",num,c);
    return 0;
}