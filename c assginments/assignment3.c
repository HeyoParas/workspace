#include<stdio.h>
#include<stdlib.h>
void AreaOfRec(float l, float b)
{
   float rec = l*b;
    printf("area of rectangle is :%.5f\n\n",rec);
}
void AreaOfCircle(float r)
{
    float circle = 3.14*r*r;
    printf("area of circle is :%.5f\n\n",circle);
}
void AreaOfTriangle(float b, float h)
{
    float triangle = 0.5 *b *h;
    printf("area of triangle is :%.5f\n\n",triangle);
}
int main ()
{
    int choice;
    while(1)
    {
       printf("Press 1 for area of circle\nPress 2 for area of rectangle\nPress 3 for area of triangle\nPress 0 for exit\ninput your choice : ");
       scanf("%d",&choice);

       switch(choice)
       {
        case 0:
        exit(0);

        case 1:
        float radius;
        printf("Input radius of the circle: ");
        scanf("%f",&radius);
        AreaOfCircle(radius);
        break;

        case 2:
        float length ,breadth;
        printf("Input length and breadth of the rectangle: ");
        scanf("%f %f",&length,&breadth);
        AreaOfRec(length,breadth);
        break;

        case 3:
        float base,height;
        printf("Input base and height of the triangle: ");
        scanf("%f %f",&base,&height);
        AreaOfTriangle(base,height);
        break;

        default:
        printf("Invalid choice");
        break;
       }
    }
    return 0;
}