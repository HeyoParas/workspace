#include<stdio.h>
int main ()
{
    int mid,start=0,c=0;
    int n ;
    printf("enter the size of the array :");
    scanf("%d",&n);
    int end=n-1,arr[n];
    printf("enter the sorted array \n");
       for(int i=0;i<n;i++)
    {
        printf("enter the a[%d] element of the array :",i);
        scanf("%d",&arr[i]);
    }
    int element,pos;
    printf("enter the element you want to search in array :");
    scanf("%d",&element);
     while(start<=end)
    {
        mid=start+(end-start)/2;
        if(element == arr[mid])
        {
            c++;
            printf("element is found at : arr[%d]",mid);
            break;
        }
        else if(element>arr[mid])
        {
            start=mid+1;
        }
        else if(element<arr[mid])
        {
            end=mid-1;
        }
    }
    if(c==0)
    {
        printf("element not found");
    }
    return 0;
}
    

    
    