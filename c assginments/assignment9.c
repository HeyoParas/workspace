#include<stdio.h>
int main ()
{
    int num,x=0;
    printf("enter the range :");
    scanf("%d",&num);
    for(int i=2;i<=num;i++)
    {
        int count=0;
        for(int j=2;j<=i/2;j++)
        {
            if(i%j==0)
            {
                count++;
                break;
            }
        }
        if(count==0)
        {
            x++;
        }
    }
    int arr[x],y=0;
        for(int i=2;i<=num;i++)
    {
        int count=0;
        for(int j=2;j<=i/2;j++)
        {
            if(i%j==0)
            {
                count++;
                break;
            }
        }
        if(count==0)
        {
            arr[y]=i;
            y++;
        }
    }
    
    for(int i=0;i<x;i=i+2)
    {
        printf("%d ",arr[i]);
    }


    return 0;
}