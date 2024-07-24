//count frequency of the duplicate element in the sorted array using binary sort
#include<stdio.h>

static int count=0;
int duplicate(int arr[],int start ,int end, int targ)
{
    if(start>end)
    {
        return -1;
    }
    int mid=(start+end)/2;
    if(arr[mid]==targ)
    {
        count++;
        return duplicate(arr,start,mid-1,targ) + duplicate(arr,mid+1,end,targ);
    }
    else if(arr[mid]>targ)
    {
        duplicate(arr,start,mid-1,targ);
    }
    else
    {
        duplicate(arr,mid+1,end,targ);
    }
}
int main ()
{
int arr[]={1,2,4,5,5,5,5,6,7,8,9};
int n=sizeof(arr)/sizeof(arr[0]);
int element=5;
int res=duplicate(arr,0,n-1,element);
if(res==-1)
{
    printf("frequency notfound");
}
else{
    printf("frequency of element :%d is %d",element,count);
}
    return 0;
}