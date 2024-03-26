#include<stdio.h>
int main ()
{
    int n,c=0;
    printf("enter the size of the array :");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        printf("enter the a[%d] element of the array :",i);
        scanf("%d",&arr[i]);
    }
    int element,pos;
    printf("enter the element you want to search in array :");
    scanf("%d",&element);
    for(int i=0;i<n;i++)
    {
        if(arr[i]==element)
        {
            pos=i;
            c++;
            break;
        }
    }
    if(c==0)
    {
        printf("element not found\n");
    }
    else
    {
        printf("element is found at :arr[%d]",pos);
    }
    return 0;
}