//WAP TO SUM OF THE DIAGONAL ELEMENTS OF THE 2D MATRIX
#include<stdio.h>
int main ()
{
    int n,sum=0;
    printf("enter the size of the 2d matrix :");
    scanf("%d",&n);
    int arr[n][n],arr2[n][n];
    printf("enter the element of the 1st 2d array\n");
    for(int i = 0 ;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    printf("enter the element of the 2st 2d array\n");
    for(int i=0;i<n;i++)
    {
       for(int j=0;j<n;j++)
       {
            scanf("%d",&arr2[i][j]);
       }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            arr[i][j]=arr[i][j]+arr2[i][j];
        }
    }
    printf("after adding matrix\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}