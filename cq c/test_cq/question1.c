//return index of that number whose left and right  sum of all elements are equal

int returnsum(int arr[],int start,int end)
{
    int sum=0;
    for (int i=start;i<end;i++)
    {
        sum=sum+arr[i];
    }
    return sum;
}

int index(int arr[],int n)
{
    int mid=1;
    int pre_sum,post_sum;
    while(mid!=n)
    {
        pre_sum=returnsum(arr,0,mid);
        post_sum=returnsum(arr,mid+1,n);
        if(pre_sum==post_sum)
        {
            return mid;
        }
        else
        mid++;
    }
}
#include <stdio.h>

int main()
{
   int arr[]={-5,3,7,4,-2,5,2};
   int n=7;
   printf("%d",index(arr,n));

    return 0;
}
