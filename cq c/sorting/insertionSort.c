#include<stdlib.h>
#include<stdio.h>

void insertion(int arr[], int n) {
int i,j;
for(i=1;i<n;i++)
{
    int temp=arr[i];
    for( j=i-1;j>=0;j--)
    {
        if(arr[j]>temp)
        {
            arr[j+1]=arr[j];
        }
        else
        break;
    }
    arr[j+1]=temp;
}

for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}

int main()
{
    int arr[]={7,4,2,8,9,3};
    int n=6;
    insertion(arr,n);
    
}