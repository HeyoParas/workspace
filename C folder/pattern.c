#include<stdio.h>
int main ()
{
    int size,org,n,x,element;
    printf("enter the size :");
    scanf("%d",&size);         
    org=size;                
    element=size;           
    n=(2*size)-1;            
    x=n;                    
    int arr[n][n];          
    int a=1,b=1;
    while(org)
    {
        for(int i=a;i<=n;i++)
        {
            for(int j=b;j<=n;j++)
            {
                arr[i][j]=element;
            }
        }
        a++;
        b++;
        n--;
        element--;
        org--;
    }
    
        for(int i=1;i<=x;i++)
        {
            for(int j=1;j<=x;j++)
            {
                printf("%d ",arr[i][j]);
            }
            printf("\n");
        }
    return 0;
}