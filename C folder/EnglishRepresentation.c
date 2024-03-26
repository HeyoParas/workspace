#include<stdio.h>
int main ()
{
     int a, b; 
  char *num[] = {"zero","one","two","three","four","five","six","seven","eight","nine"}; 
  printf("Enter two numbers: "); 
  scanf("%d %d",&a,&b); //a=7,b=13

  for (int i=a; i<=b; i++)
   { 
    if (i<=9) 
    {
      printf("%s\n",num[i]);
    } 
    else if (i>9 && i%2==0)
    {
      printf("even\n");
    } 
    else if (i>9 && i%2!=0)
    { 
      printf("odd\n");
    }
   }
    return 0;
}