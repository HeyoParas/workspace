#include <stdio.h>
int main()
{
    int num,rem,res=0,x,i=0;
    printf("enter the number : ");
    scanf("%d",&num);
    sos:
    if(i)
    {
        num=x;
    }
    while(num)
    {
        rem=num%10;
        res=res+rem;
        num=num/10;
    }
    x=res;
    if(x>9)
    {
        i++;
        res=0;
        rem=0;
        goto sos;
    }
    printf("%d",res);
    int count=0;
    for(int i=2;i<=res/2;i++)
    {
        if(res%i==0)
        {
            count++;
        }
    }
    if(count>0)
    {
        printf("not prime");
    }
    else
    printf("prime");
    return 0;
}

