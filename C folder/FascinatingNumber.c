#include<stdio.h>
int logic(int n)
{
    int sum=0,ans;
    for(int i=1;i<=3;i++)
    {
        ans=n*i;
        sum=sum+ans;
    }
    
    return sum;
}
int main ()
{
    int num,n=1,c=0;
    printf("enter the number: ");
    scanf("%d",&num);
    int check[10]={0};
    int org=num;
    int res=logic(num);
    while(res)
    {
        int rem=res%10;
        check[rem]++;
        res=res/10;
    }
    for(int i=1;i<10;i++)
    {
        if(check[i]==1)
        {
            c++;
        }
    }
    if(c==9)
    {
        printf("%d is fascinating number",org);
    }
    else
    {
        printf("%d not a fascinating number",org);
    }
   
    return 0;
}