#include <stdio.h>

int main()
{
    int arr[]={3,1,-2,-5,2,-4};
    int n=6,res[n],j=0,k=1;
     for(int i=0;i<n;i++)
    {
        if(arr[i]>=0)
        {
                res[j]=arr[i];
                j=j+2;
        }
        
        if(arr[i]<0)
        {
                res[k]=arr[i];
                k=k+2;
        }
    }
    for(int i=0;i<n;i++)
    {
        printf("%d",res[i]);
    }

    return 0;
}