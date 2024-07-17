#include<stdio.h>
int main ()
{
    int n=6;
    int arr[6]={3,5,2,1,4,3};
    int max_p=0;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]-arr[i]>max_p)
            max_p=arr[j]-arr[i];
        }
        
    }
    printf("%d",max_p);
    
    return 0;
}