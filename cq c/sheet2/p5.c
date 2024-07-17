//reverese the string
int getlen(char s[])
{   
    int len=0,i=0;
    while(s[i]!= '\0')
    {
        len++;
        i++;
    }
    return len;
}

char* reverse(char s[],int len)
{
    for (int i=0;i<len/2;i++)
    {
        int temp=s[i];
        s[i]=s[len-i-1];
        s[len-i-1]=temp;
    }
    return s;
}

#include<stdio.h>
int main() {

char str[]="paras";
int length=getlen(str);
printf("reverse string : %s",reverse(str,length));

    
    return 0;
}