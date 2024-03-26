// //conversion of the dollar money into the indian ruppee
// #include<iostream>
// using namespace std;
// //source class
// class dollar                    
// {
//     double dol;         //member instances
//     public :
//     dollar(){};            //default constructor
//     dollar(double n)            //parameterised constructor
//     {
//         dol=n;
//     };
//     void show()         //display's dollar
//     {
//         cout<<"money in dollar:"<<dol<<endl;
//     }
//     double getdollar()          //return dollar to destination class for conversion
//     {
//         return dol;
//     }
// };
// //destination class
// class ruppee
// {
//     double rupay;           //member instances
//     public:
//     ruppee(){};         //default constuctor
//     ruppee(dollar dol)          //paramterised constructor
//     {
//         rupay=dol.getdollar()*80.00;
//     }
//     void show()         //show dollar into ruppee currency
//     {
//         cout<<"Ruppee :"<<rupay;
//     }
// };
// int main ()
// {
//     dollar obj(5);
//     ruppee obj2=obj;
//     obj2.show();
//     return 0;
// }



//conversion of the dollar money into the indian ruppee using overloading casting operator
#include<iostream>
using namespace std;
//destination class
class ruppee
{
    double rupay;           //member instances
    public:
    ruppee(){};         //default constuctor
    ruppee(double dol)          //paramterised constructor
    {
        rupay=dol;
    }
    void show()         //show dollar into ruppee currency
    {
        cout<<"Ruppee :"<<rupay;
    }   
};
//source class
class dollar                    
{
    double dol;         //member instances
    public :
    dollar(){};            //default constructor
    dollar(double n)            //parameterised constructor
    {
        dol=n;
    };
    operator ruppee()         //display's dollar
    {
        return ruppee(dol*80);
    }
};
int main ()
{
   dollar ob1(5);
   ruppee ob2=ob1;
   ob2.show();
    return 0;
}