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
    myclass (myclass &obj1)
    {
        a=obj1.a;
        b=obj1.b;
    }
    myclass add(myclass &obj1)
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
   myclass obj4(obj1);
   obj4.showdata();
   obj3=obj2.add(obj1);

    return 0;
    }