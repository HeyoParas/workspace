// #include<stdio.h>
// int main ()
// {
// int i,j;
// int arr[]={1,2,3,4,5,6,7,8};
// int n=8,start=0,end=n-1,sum,x=5,count=0;
// while(start<end)
// {
//     sum=arr[start]+arr[end];
//         if(sum==x)
//         {
//             start++;
//             end--;
//             count++;
//         }
//         else if(sum<x)
//         {
//             start++;
//         }
//         else{
//             end--;
//         }
// }
// printf("%d",count);
//     return 0;
// }

#include<stdio.h>
int main ()
{
int i,j;
int arr[]={-9,2,-1,4,-10,6,-4,8};
int n=8;
for(i=1;i<n;i++)
{
    int temp=arr[i];
    if(arr[i]<0)
    continue;
    for( j=i-1;j>=0;j--)
    {
        if(arr[j]<0 )
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
    return 0;
}
