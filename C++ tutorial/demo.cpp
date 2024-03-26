#include<iostream>
using namespace std;
class A
{
    int a;
    public:
    A(int x)
    {
        a=x;
        cout<<"i am in parent const\n";
    }
    ~A()
    {
        cout<<"A destructor called\n";
    }
};
class B:public A
{
    int m;
    public:
    B(int x, int y):A(y)
    {
        m=x;
        cout<<"i am in child const\n";
    }
   ~B()
   {
    cout<<"B destructor called\n";
   }
};
int main()
{
   B obj(10,20);
    return 0;
}