#include<stdio.h>
int main ()
{
    int num;
    float larg1=0,larg2=0;
    float avg;
    printf("enter the number: ");
    scanf("%d",&num);
        while(num)
        {
        int rem=num%10; 
        if(rem>larg1)
        {
            larg2=larg1;
            larg1=rem;
        }
        else if(rem<larg1 && rem>larg2)
        {
            larg2=rem;
        }
        num=num/10;      
        }
        avg=(larg1+larg2)/2;
        printf("Average of two highest numbers = %.1f",avg);
    return 0;
}