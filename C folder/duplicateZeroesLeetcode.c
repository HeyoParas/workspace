#include <stdio.h>

int main()
{
    int arr[]={1,0,1,0,5,0,3};//1 0 0 1 0 0 5
    int n=sizeof(arr)/sizeof(int);
    int pos;
for(int i=0;i<n;i++)
{
  if(arr[i]==0)
  {
    pos=i;
    for(int i=n-1;i>pos;i--)
    {
      arr[i+1]=arr[i];
    }
    arr[pos+1]=0;
    pos=0;
    i++;
  }
}
for(int i=0;i<n;i++)
{
    printf("%d",arr[i]);
}

    return 0;
}