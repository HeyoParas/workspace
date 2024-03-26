#include<stdio.h>
int main ()
{
	int i,j,n,x=0,row,column,loc,choice;
	printf("enter the size of the 2-D array:");
	scanf("%d",&n);
	int array[n][n],arr[n*n];
	printf("enter the elements of the 2-D array\n");
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&array[i][j]);
            if(array[i][j]!=0)
            {
                arr[x]=array[i][j];
                x++;
            }
		}
	}
    // for(int i=0;i<x;i++)
    // {
    //     printf("%d ",arr[i]);
    // }
	printf("enter the row and column of the 2-D matrix in order to find elements :");
	scanf("%d %d",&row,&column);
	loc = (row*(row-1))/2 + column;
	loc = loc-1;
	while(choice!=0)
	{	
	printf("the element is :%d\n",arr[loc]);
	printf("enter 0 for exit and 1 for continue");
	scanf("%d",&choice);
	}
	return 0;

}