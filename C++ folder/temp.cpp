//constructor using default arguement
#include<iostream>
using namespace std;
class sample
{
    int a;
    public: 
    void show()
    {
        cout << a<< endl;
    }
    sample()
    {}
    sample(int n)
    {
        a=n;
    }
    sample(sample &new)
    {
        a=new.a;
    }
};

int main()
{
     sample obj1(4);
     sample obj2(obj1);
     
}