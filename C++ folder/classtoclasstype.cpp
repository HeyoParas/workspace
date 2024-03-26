#include<iostream>
using namespace std;
//destination class
class inches
{
    int inch;           //member instances
    public:
    inches(){};         //default constuctor
    inches(int feet)          //paramterised constructor
    {
        inch=feet;
    }
    void show()         
    {
        cout<<"inches :"<<inch;
    }   
};
//source class
class feets                    
{
    int feet;         //member instances
    public :
    feets(){};            //default constructor
    feets(int n)            //parameterised constructor
    {
        feet=n;
    };
    operator inches()         //display's feets
    {
        return inches(feet*12);
    }
};
int main ()
{
   feets ob1(5);
   inches ob2=ob1;
   ob2.show();
    return 0;
}