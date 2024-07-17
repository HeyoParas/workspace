//deletion of array element from position
#include <stdio.h>
int main()
{
    int n=7;
    int arr[7]={45,36,7,4,36,6,3};
    int p;
    printf("enter the position:");
    scanf("%d",&p);
    int pos=p-1;

    for(int i=pos;i<n-1;i++)
    {
       arr[i]=arr[i+1];
    }
    n--;
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}