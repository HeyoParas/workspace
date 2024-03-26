//logic 1
#include <stdio.h>

int main()
{
    
    int n,temp;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int k;
    scanf("%d",&k);
    k=k%n;
        while(k)
    {
        temp=arr[n-1];
        for(int i=n-1;i>=0;i--)
        {
            arr[i]=arr[i-1];
        }
        arr[0]=temp;
        k--;
    }
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }

    return 0;
}


// logic 2nd
#include <stdio.h>

int main()
{
    
    int n,temp,a;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int k;
    scanf("%d",&k);
    a=n-k;//a=4
 
        for(int i=0;i<a/2;i++)
        {
            int temp=arr[i];
            arr[i]=arr[a-i-1];
            arr[a-i-1]=temp;
        }
         for(int i=0;i<n/2;i++)
    {
        temp=arr[i];
        arr[i]=arr[n-i-1];
        arr[n-i-1]=temp;
    }
    for(int i=0;i<k/2;i++)
    {
        int temp=arr[i];
        arr[i]=arr[k-i-1];
        arr[k-i-1]=temp;
    }
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }

    return 0;
}