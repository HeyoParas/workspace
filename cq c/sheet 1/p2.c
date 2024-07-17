// frequency of given number
#include <stdio.h>
int main()
{
    int n=10;
    int arr[10]={2,2,1,4,2,5,1,10,9,2};
    int larg=arr[0];
    for(int i=1;i<n;i++)
    {
        if(arr[i]>larg)
        larg=arr[i];
    }
    int *temp=calloc(larg+1, sizeof(int));
    int elem;
    printf("enter the number to be searched:");
    scanf("%d",&elem);
    for(int i=0;i<n;i++)
    {
       temp[arr[i]]++;
    }
    printf("the frequency of %d :%d",elem,temp[elem]);
return 0;
}