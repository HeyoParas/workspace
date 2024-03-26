#include<stdio.h>
int main ()
{
    int n;
    printf("enter the size of the array :");
    scanf("%d",&n);
    int arr[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("enter the arr[%d][%d] element of the 2D array :",i,j);
            scanf("%d",&arr[i][j]);
        }
    }
     for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i>j || i==j)
            {
            printf("%d  ",arr[i][j]);
            printf("    ");
            }
        }
            printf("\n");
    }
    return 0;
}