//find duplicate element using recursion
#include<stdio.h>
int duplicate(int arr[],int start,int end)
{
        int mid=(start+end)/2;
        if(start >= end)
        return -1;
        if(arr[mid]==arr[mid+1] || arr[mid-1]==arr[mid])
        return mid;
        else 
        {
             if(duplicate(arr,start,mid-1)==-1)
             {
               return duplicate(arr,mid+1,end);
             }
        }
}
int main ()
{
    int arr[]={1,-2,-2,8,7,4,5,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    int res=duplicate(arr,0,n);
    printf("duplicate is : %d",arr[res]);
    return 0;
}