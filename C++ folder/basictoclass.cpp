#include<iostream>
using namespace std;
class conversion
{
    int feet,inches;
    public:
    conversion(int t)
    {
        feet=inches/12;
        inches=inches%12;
    }
    void show()
    {
        cout<<"feet :"<<feet<<"inches :"<<inches<<endl;
        cout<<feet<<"'"<<inches;
    }

};
int main()
{
    int inches=150;
    conversion obj1 =inches;
    obj1.show();
    return 0;
}