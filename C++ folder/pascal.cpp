#include<iostream>
#include<iomanip>
using namespace std;
int fact (int n)
{
    int f=1;
    for(int i=1;i<=n;i++)
    {
        f=f*i;
        
    }
    return f;
}
int combination(int n,int r )
{
    return fact(n)/(fact (n-r)*fact(r));
}
int main()
{
    int n;
    cout<<"enter the size of the pascal triangle :";
    cin>>n;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n-i;j++)
        {
            cout<<" ";
        }
        for(int k=0;k<=i;k++)
        {
            cout<<setw(4)<<combination(i,k);
        }
        cout<<endl;
    }
    return 0;
}