#include<stdio.h>
#include<math.h>
int main ()
{
    int n,o,sum=0,num=9,power=0,res=0;
    printf("Input in number of terms:");
    scanf("%d",&n);
    o=n;
    while(o)
    {
        res=num*pow(10,power)+res;
        printf("%d ",res);
        sum=sum+res;
        power++;
        o--;
    }
    printf("\n");
    printf("The sum of the series = %d",sum);
    return 0;
}