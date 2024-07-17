//capitalized first string
char* getcapital(char s[])
{   
    int i=0;
    s[i]=s[i]-32;
    while(s[i]!='\0')
    {
        if(s[i]==' ')
        {
            s[i+1]=s[i+1]-32;
        }
        i++;
    }
    return s;
}
#include<stdio.h>
int main() {

    char str[] = "code quotient";
    printf("%s",getcapital(str));
    
    return 0;
}