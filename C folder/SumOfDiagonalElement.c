//WAP TO SUM OF THE DIAGONAL ELEMENTS OF THE 2D MATRIX
#include<stdio.h>
int main ()
{
    int n,sum=0;
    printf("enter the size of the 2d matrix");
    scanf("%d",&n);
    int arr[n][n];
    printf("enter the element of the 2d array");
    for(int i = 0 ;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    for(int i=0;i<n;i++)
    {
        sum=sum+arr[i][i];
    }
    printf("the sum of the diagonal matrix is: %d ",sum);

    return 0;
}