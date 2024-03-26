#include<iostream>
#include<stdlib.h>
using namespace std;
class account
{
    private :
    char name[20],acc_type[20];
    double long acc_no,balance;
    public :
    void input()
    {
        cout<<"enter the name :";
        cin>>name;
        cout<<"enter the account type :";
        cin>>acc_type;
        cout<<"enter the account number :";
        cin>>acc_no;
        cout<<"enter the balance :";
        cin>>balance;
    }
    void deposite(long amount)
    {
        balance=balance+amount;
        display();
    }
    void withdraw(long amount)
    {
        if(balance>=amount)
        {
            balance=balance-amount;
        }
        else
        {
            cout<<"insufficient balance\n";
        }
        display();
    }
    void display()
    {
        cout<<"your current balance is :"<<balance<<endl;
    }
};
int main()
{
    account customer;
    int choice;
    long amount;
    while(1)
            {
            cout<<"<------------------>\n";
            cout<<"1:For open an account\n";
            cout<<"2:For deposite amount in account\n";
            cout<<"3:For withdraw money from account\n";
            cout<<"4:For display balance of account\n";
            cout<<"5:For exit\n";
            cout<<"<------------------>\n";
            cout<<"enter your choice :";
            cin>>choice;
            switch(choice)
                    {
                        case 1:
                                customer.input();
                                break;
                        case 2:
                                cout<<"enter the amount you want to deposite :";
                                cin>>amount;
                                customer.deposite(amount);
                                break;
                        case 3:
                                cout<<"enter the amount you want to withdraw :";
                                cin>>amount;
                                customer.withdraw(amount);
                                break;
                        case 4:
                                customer.display();
                                break;
                        case 5:
                                exit(0);
                        default:
                                cout<<"invalide choice\n";
                                break;
                    }
            }
    return 0;
}