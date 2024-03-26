#include<stdio.h>
int maxSubArray(int* arr, int numSize){
    int max=arr[0],sum=0;
for(int i=0;i<numSize;i++)
{
    sum=sum+arr[i];
    if(sum>max)
    {
        max=sum;
    }
    if(sum<0)
    {
        sum=0;
    }
}
return max;
}
int main ()
{
    int n,res;
    printf("enter the size of array :");
    scanf("%d",&n);
    int arr[n];
    printf("enter the element if array :");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    res=maxSubArray(arr,n);
    printf("%d",res);
    return 0;
}