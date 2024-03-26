#include<iostream>
using namespace std;
class myclass
{
    int a;
    int b;
    public:
    myclass()
    {
        
    }
    myclass(int x,int y)
    {
     a=x;
     b=y;
    }
    myclass operator +(myclass obj1)
    {   
        myclass temp;
        temp.a=a+obj1.a;
        temp.b=b+obj1.b;
        return temp;
    }
    void showdata()
    {
        cout<<a<<":::"<<b;
    }
};
int main ()
{
   myclass obj1(10 ,80);
   myclass obj2(40, 20);
   myclass obj3;
   //obj3=obj2.operator+(obj1);
   obj3=obj2+obj1;
   obj3.showdata();

    return 0;
}