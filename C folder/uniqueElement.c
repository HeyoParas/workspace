#include<stdio.h>
int main()
{
    int n,x,c;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n;i++)
    {
        c=1;
        for(int j=0;j<n;j++)
        {
            if(i!=j && arr[i]==arr[j])
            {
                c=0;
                break;
            }
        }
        if(c)
        {
            printf("%d",arr[i]);
        }
    }
    return 0;
}