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
        int larg=arr[0];
        int larg_idx=i;

        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[larg_idx])
            {
                larg=arr[j];
                larg_idx=j;
            }
        }
         swap(&arr[larg_idx],&arr[i]);
        
    }
    
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}
int main ()
{
    int arr[6]={3,14,17,11,9,1};
    int n=6;
    selection(arr,n);
    return 0;
}