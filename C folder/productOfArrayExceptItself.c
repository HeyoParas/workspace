#include <stdio.h>

int main()
{
    long arr[]={1,2,3,4};
    long n=sizeof(arr)/sizeof(arr[0]);
    printf("%d\n",n);
    int res[n];
        int pro=1;
for(int i=0;i<n;i++)
{
    for(int j=0;j<n;j++)
    {
        if(i!=j)
        {
            pro=pro*arr[j];
        }
    }
    res[i]=pro;
    pro=1;
}

 for(int i=0;i<n;i++)
    {
        printf("%d ",res[i]);
    }
    return 0;
}