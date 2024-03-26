#include<iostream>
#include<stdlib.h>
using namespace std;
class bank
{
    public:
    char name[20];
    long account_number;
    long balance;
    char account_type;
    void getdata()
    {
        cout<<"enter name of customer :";
        cin>>name;
        cout<<endl;
        cout<<"enter account number :";
        cin>>account_number;
        cout<<endl;
        cout<<"enter your balance:";
        cin>>balance;
        cout<<endl;
    }
    void deposit(double amount)
    {
        balance+=amount;
    }
    void withdraw(double amount)
    {
        if(balance<amount)
        {
            cout<<"incsuffiecient balance";
            cout<<endl;        
        }
        else
        balance-=amount;
        display();
    }
    void penalty_withdraw_for_savings(double amount)
    {
        balance = balance-amount-500;
    }
     void penalty_withdraw_for_current(double amount)
    {
        balance = balance-amount-1000;
    }
    void display()
    {
        cout<<"your current balance is : "<<balance<<endl;
    }
};

class saving:public bank
{
    int choice;
    double amount;
    public :
     saving (double n)
    {
        amount = n;
    }
    void deposit()
    {
        bank::deposit(amount);
    }
    void withdraw(double n)
    {
        if(amount>10000)
        {
            cout<<"too much amount you withdrawing"<<endl;
            cout<<"transaction failed";
            exit;
        }
        if(balance==5000)
        {
            cout<<"warning your account have Rs.5000 left"<<endl;
            cout<<"do you want to withdraw money '1' for yes or '0' for no: ";
            cin>>choice;
            if(choice == 1)
            {
                bank::penalty_withdraw_for_savings(amount);
            }
            else
            {
                exit;
            }

        }
    }
    
};
class current:public bank
{
    int choice;
    double amount;
    public :
    current (double n)
    {
        amount=n;
    }
    void deposit()
    {
        bank::deposit(amount);
    }
    void withdraw(double n)
    {
        if(amount>50000)
        {
            cout<<"too much amount you withdrawing"<<endl;
            cout<<"transaction failed";
            exit;
        }
        if(balance==10000)
        {
            cout<<"warning your account have Rs.10000 left"<<endl;
            cout<<"do you want to withdraw money '1' for yes or '0' for no: ";
            cin>>choice;
            if(choice == 1)
            {
                bank::penalty_withdraw_for_current(amount);
            }
            else
            {
                exit;
            }

        }
    }
    void display()
    {
        bank::display();
    }

};

int main()
{
    int ch;
    double amount;
    // while(1)
    // {
    //     cout<<"which type of account you wants to open?"<<endl;
    //     cout<<"1.for savings account"<<endl;
    //     cout<<"2.for current aacount"<<endl;
    //     cin>>ch;
    //     switch(ch)
    //     {
    //             case 1:
    //             bank b1;
    //             b1.getdata();
             
    //     }

    // }
 bank b1;
 b1.getdata();
 b1.display();
 current c1(10000);
c1.display();
 
 
    return 0;
}