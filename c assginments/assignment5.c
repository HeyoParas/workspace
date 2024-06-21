#include <stdio.h>
int main()
{
    int a,b;
    printf("enter the first interval :");
    scanf("%d",&a);
    printf("enter the second interval :");
    scanf("%d",&b);
    char *arr[]={"zero","one","two","three","four","five","six","seven","eight","nine"};
    for(int i=a;i<=b;i++)
    {
        if(i<10)
        printf("%s \n",arr[i]);
        else if (i>9 && i%2==0)
        printf("even\n");
        else
        printf("odd\n");
    }
    return 0;
}