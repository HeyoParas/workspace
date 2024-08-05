#include<stdio.h>
void swap(int *a,int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void selection(int arr[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        int small=arr[0];
        int small_idx=i;

        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[small_idx])
            {
                small=arr[j];
                small_idx=j;
            }
        }
         swap(&arr[small_idx],&arr[i]);
        
    }
    
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}
int main ()
{
    int arr[]={3,14,17,6,7,3,4,9,11,9,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    selection(arr,n);
    return 0;
}