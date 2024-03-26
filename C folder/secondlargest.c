#include<stdio.h>
void second_largest(int arr[], int n)
{
	int larg1,larg2;
	larg1=arr[0];
	larg2=arr[1];
	if(arr[1]>arr[0])
	{
		larg1=arr[1];
		larg2=arr[0];
	}
   for(int i=2;i<n;i++)
   {
	if(larg1>arr[i] && larg2<arr[i])
	{
		larg2=arr[i];
	}
	else if (larg1<arr[i] && larg2<arr[i])
	{
		larg2=larg1;
		larg1=arr[i];
	}
	else if (arr[i]==larg1 && arr[i]==larg2)
	{
       printf("there is no second largest number in array");
       return 0;
	} 
   }
   printf("the second largest element in the array is = %d",larg2);
}

int main()
{
int n;
printf("enter the number of elements in the array=");
scanf("%d",&n);
int arr[n];
for ( int i = 0; i < n; i++)
{
	printf("enter the a[%d] elements of the array =",i);
	scanf("%d",&arr[i]);
}
second_largest(arr,n);


return 0;
}