#include<iostream>
using namespace std;
class calculator 
{
    float num1;
    float num2;
    public :
    void input()
    {
        cin>>num1;
        cin>>num2;
    }
    
};
int main ()
{
    int choice;
    cout<<"which operation you have to perform"<<endl;
    switch(1)
    {
    cout<<"1 addition"<<endl;
    cout<<"2 subtract"<<endl;
    cout<<"3 divide"<<endl;
    cout<<"4 multiply"<<endl;
    cout<<"enter the choice"<<endl;
    cin>>choice;
    
    }
    return 0;
}