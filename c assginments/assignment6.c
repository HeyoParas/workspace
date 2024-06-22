#include <stdio.h>
int main()
{
    int num,sum=0;
    printf("enter the number : ");
    scanf("%d",&num);
    for(int i=1;i<=num/2;i++)
    {
        if(num%i==0)
        {
            printf("%d ",i);
            sum=sum+i;
        }
    }
    if(sum==num)
    {
        printf("\nperfect");
    }
    else
    printf("\nnot perfect");
    
    return 0;
}