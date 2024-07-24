
#include<stdio.h>
void bubble(int arr[], int n) {
int i,j;
for(i=0;i<n-1;i++)
{
    for( j=0;j<n-i-1;j++)
    {
        if(arr[j]>arr[j+1])
        {
            int temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
        }
    }
}
for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}

int main ()
{
     int arr[]={7,4,2,8,9,3};
    int n=6;
    bubble(arr,n);

    return 0;
}