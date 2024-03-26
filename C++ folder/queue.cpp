#include<iostream>
#define n 4
using namespace std;
int front=-1,rear=-1;
class queue 
{
    private :
    int arr[n];
    public :
    void del()
    {
        int item;
        if(front==-1)
        {
            cout<<"queue is empty";
            return;
        }
        else
        {
           item = arr[front];
            front++;
              
        }
    }
     void insert(int item)
    {
        if(rear==n-1)
        {
            cout<<"overflow\n";
            cout<<"<----------->\n";
            return;
        }
       else if(front==-1)
        {
            front=0;
            rear++;
            arr[rear]=item;
        }
        
    }
    void display();
};
void queue::display()
{
    for(int i=front;i<=rear;i++)
    {
        cout<<arr[front]<<"\t";
    }
    cout<<"\n<------------>\n";
}
int main ()
{
    queue q1;
    int choice;
    while(1)
{
cout<<"1:for insert item in queue\n";
cout<<"2:for delete item from queue\n";
cout<<"3:for display item of queue\n";
cout<<"0:for exit\n";
cout<<"enter your choice :";
cin>>choice;
switch(choice)
{
    case 1:
    int element;
    cout<<"enter the element you want to insert in queue:";
    cin>>element;
    q1.insert(element);
    break;
    case 2:
    q1.del();
    q1.display();
    break;
    case 3:
    q1.display();
    break;
    case 0:
    exit(0);

}
}
    return 0;
}
