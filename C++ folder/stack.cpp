#include<iostream>
#include<stdlib.h>
#define n 4
using namespace std;
int top=-1;
class stack
{
private:
    int arr[n];
    int item;
public:
    void push(int item)
    {
        if(top==n-1)
        {
            cout<<"overflow\n";
        }
        else
        {
            top++;
            arr[top]=item;
        }
    }
    int pop()
    {
        int temp;
        if(top==-1)
        {
            cout<<"stack is empty\n";
        }
        else
        {
            temp=arr[top];
            top--;
        }
    }
    void display();
};
void stack::display()
{
    if(top==-1)
    {
        cout<<"stack is empty\n";
    }
    else
    {
        for(int i=top;i>=0;i--)
        {
            cout<<arr[i]<<endl;
        }
    }
}
int main ()
{
    int choice;
    stack s1;

while(1)
{
cout<<"1:for insert item in stack\n";
cout<<"2:for delete item from stack\n";
cout<<"3:for display item of stack\n";
cout<<"0:for exit\n";
cout<<"enter your choice :";
cin>>choice;
switch(choice)
{
    case 1:
    int element;
    cout<<"enter the element you want to insert in stack:";
    cin>>element;
    s1.push(element);
    break;
    case 2:
    cout<<"pop function called :"<<s1.pop()<<endl;
    s1.display();
    break;
    case 3:
    s1.display();
    break;
    case 0:
    exit(0);

}
}

return 0;
}


