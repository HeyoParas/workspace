//count length of the string
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
#include<stdio.h>
int main() {

    char str[] = "get better at coding.";
    printf("%d",getlen(str));
    
    return 0;
}