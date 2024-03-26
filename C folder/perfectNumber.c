#include <stdio.h>

int main()
{
    int n,sum=0;
    printf("enter the number :");
    scanf("%d",&n);
    printf("The positive divisor :");
    for(int i=1;i<=n/2;i++ )
    {
        if(n%i==0)
        {
            printf("%d ",i);
            sum=sum+i;
        }
    }
    if(sum==n)
    {
        printf("\nThe sum of the divisor is :%d\n",sum);
        printf("The number is perfect");
    }
    else
    {
        printf("\nThe number is not perfect");
    }
    return 0;
}
