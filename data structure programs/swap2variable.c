#include<stdio.h>
void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}
int main ()
{
    int num1=10;
    int num2=20;
    printf("num1 before swapping :%d \n",num1);
    printf("num2 before swapping :%d\n",num2);
    swap(&num1,&num2);
    printf("after swaping\n");
    printf("num1 before swapping :%d \n",num1);
    printf("num2 before swapping :%d",num2);


    return 0;
}