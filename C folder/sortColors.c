#include <stdio.h>

int main()
{
    int arr[]={2,0,1};
    int n=3;
        int zero=0,one=0,two=0;
for(int i=0;i<n;i++)
{
    if(arr[i]==0)
    {
        zero++;
    }
    if(arr[i]==1)
    {
        one++;
    }
    if(arr[i]==2)
    {
        two++;
    }
}
for(int i=0;i<zero;i++)
{
    arr[i]=0;
}
for(int i=zero;i<zero+one;i++)
{
    arr[i]=1;
}
for(int i=zero+one;i<n;i++)
{
    arr[i]=two;
}
 for(int i=0;i<n;i++)
    {
        printf("%d",arr[i]);
    }

return 0;
}