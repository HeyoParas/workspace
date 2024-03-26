#include <stdio.h>

int main()
{
    int arr[]={0};
    int n=1;
    int j=0;
for(int i=0;i<n;i++)
{
   if(arr[i]%2==0)
   {
       int temp=arr[i];
       arr[i]=arr[j];
       arr[j]=temp;
       j++;
   }
}
for(int i=0;i<n;i++)
{
    printf("%d",arr[i]);
}

    return 0;
}