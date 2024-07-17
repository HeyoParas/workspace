//cut the substring
#include<stdio.h>
int main() {

char str[]="this is test string";
int pos;
printf("enter the postion from where u want to trim:");
scanf("%d",&pos);
pos--;
int size;
printf("enter the size for trim the string: ");
scanf("%d",&size);
for(int i=pos;i<pos+size;i++)
{
   printf("%c",str[i]);
}  
    return 0;
}