//vowels and consonant count
#include<stdio.h>
int main() {

char str[]="leevance singh";
int i=0;
int vowels=0,consonant=0;
while(str[i]!='\0')
{
    if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u'||str[i]=='A'||str[i]=='E'||str[i]=='I'||str[i]=='O'||str[i]=='U')
    vowels++;
    else if(str[i]>='A'&&str[i]<='Z' || str[i]>='a'&&str[i]<='z')
    consonant++;
    i++;
}
printf("%d",vowels);
printf("\n%d",consonant);
    
    return 0;
}