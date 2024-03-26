#include<stdio.h>
int main()
{
    int chem,phy,math,total,totalOfMathandPhy;
    printf("enter the marks of chemistry :");
    scanf("%d",&chem);
    printf("enter the marks of physics :");
    scanf("%d",&phy);
    printf("enter the marks of math :");
    scanf("%d",&math);
    total=chem+phy+math;
    totalOfMathandPhy=math+phy;
    if((math>=65 && phy>=55 && chem>=50 && total>=190)||totalOfMathandPhy>=140)
    {
        printf("The candidate is eligible for admission");
    }
    else
    {
        printf("The candidate is not eligible for admission");
    }
    return 0;
}