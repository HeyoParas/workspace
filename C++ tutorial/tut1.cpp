#include<iostream>
using namespace std;
//reference variable
int main()
{
    int x; //ordinary var
    x=5;
    cout<<5<<endl;
    int *p; //pointer var
    p=&x;
    cout<<*p<<endl;
    int &r=x; //reference var(R is a refrence variable in which the reference of x is stored)
    cout<<r<<endl;
    r++;
    cout<<x;

    /*RULES :
    1. reference means address
    2.**reference variable is an internal pointer
    3.declaration of reference variable is preceded with "&" symbol(but don't read it as 'address of')
    4. reference variable must be initialized during declaration
    5. it can be initialized with already declared varibales
    6.refernce variables cannot be updated
    */
    return 0;
}