#include<stdio.h>
int main()
{
    int n;
    printf("enter the n=");
    scanf("%d",&n);
    int arr[n],left[n],right[n];
    left[0]=1;
    right[n-1]=1;
    //array enter
    int x=1;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i;j>=0;j--)
        {
            left[i]=x*i;
        }
    }
    return 0;
}