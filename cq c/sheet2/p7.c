//check string palindrome or not
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

int ispalindrome(char s[],int len)
{
    int count=0;
    int n=len/2;
    for (int i=0;i<n;i++)
    {
       if(s[i]==s[len-i-1])
        count++;
    }
    if(count==n)
    {
    return 1;
    }
    else
    {
    return 0;
    }
}

#include<stdio.h>
int main() {

char str[]="leevance";
int length=getlen(str);  
if(ispalindrome(str,length))
{
    printf("palindrome");
}
else
{
    printf("not palindrome");
}
  
    return 0;
}