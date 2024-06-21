#include<stdio.h>
int main()
{
    int n;
    printf("enter the month number :");
    scanf("%d",&n);
    switch (n)
    {
    case 1:
        printf("January : 31 days");
        break;

    case 2:
        printf("febuary : 28 or 29 days");
        break;

    case 3:
        printf("march : 31 days");
        break;

    case 4:
        printf("april : 30 days");
        break;

    case 5:
        printf("may : 31 days");
        break;

    case 6:
        printf("june : 30 days");
        break;

    case 7:
        printf("july : 31 days");
        break;

    case 8:
        printf("august : 31 days");
        break;

    case 9:
        printf("september : 30 days");
        break;

    case 10:
        printf("october : 31 days");
        break;

    case 11:
        printf("november : 30 days");
        break;

    case 12:
        printf("december : 31 days");
        break;
    
    default:
        printf("enter the valid month number");
        break;
    }

     
return 0;
}