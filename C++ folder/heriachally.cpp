//heriachally inheritance
#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
class Account
{
    protected:
        char name[20],acc_type[8];
        long acc_no;
        double balance;
    public: 
        void initialise()
        {
            cout<<"\nEnter Account holder name: ";
            cin.getline(name,20);
            cout<<"\nEnter Account number: ";
            cin>>acc_no;
            cout<<"\nEnter the balance: ";
            cin>>balance;
            cout<<"\nEnter the Account type(Saving/Current): ";
            cin>>acc_type;
        }
        int check_acc_type()
        {
            if(strcmp(acc_type,acc_type))
            {
                return 1;
            }
            else return 0;
        }
        void deposit(double amt)
        {
            balance=balance+amt;
        }
        void withdraw(double amt)
        {
            if(balance<amt)
            {
                cout<<"\nInsufficient Balance\nTransaction Cancelled";
            }
            else
            {
                balance=balance-amt;
            }
        }
        void display()
        {
            if(balance==0)
            {
                cout<<"\nBank Account is empty";
            }
            cout<<"\nBalance= "<<balance;
        }
};
class Current_Acc:public Account
{
    public:
       void deposit(double amt)
       {
            Account::deposit(amt);
       }
       void withdraw(double amt)
        {
            if(amt>5000)
            {
                cout<<"\nMaximum withdrawl allowed is 50000\nTransaction Cancelled";
            }
            else
            {
                Account::withdraw(amt);
            }
        }
        void check_min_bal()
        {
            if(balance<10000)
            {
                cout<<"\nAccout balance is less than 10000 so service charge of 1000/- is imposed.";
                balance=balance-1000;
            }
            Account::display();
        }
        void display()
        {
            Account::display();
        }
};
class Saving_Acc:public Account
{
    public:
        void deposit(double amt)
        {
            Account::deposit(amt);
        }
        void withdraw(double amt)
        {
            if(amt>10000)
            {
                cout<<"\nMaximum withdrawl allowed is 10000\nTransaction Cancelled";
            }
            else
            {
                Account::withdraw(amt);
            }
        }
        void check_min_bal()
        {
            if(balance<5000)
            {
                cout<<"\nAccout balance is less than 5000 so service charge of 500/- is imposed.";
                balance=balance-500;
            }
            Account::display();
        }
        void display()
        {
            Account::display();
        }
};
int main()
{
    int choice,temp;
    double amount;
    Account a;
    temp=a.check_acc_type();
    Saving_Acc sa;
    Current_Acc ca;
    sa.initialise();
    while(1)
    {
        if(temp==1)
        {
            cout<<"\nSaving Account";
            cout<<"\nEnter 1 to Deposit amount\nEnter 2 to Withdraw amount\nEnter 3 to display Balance\nEnter 4 to Check Balance\nEnter 5 to Exit";
            cout<<"\nEnter your choice: ";
            cin>>choice;
            switch(choice)
            {
                case 1:
                    cout<<"\nEnter amount to deposit: ";
                    cin>>amount;
                    sa.deposit(amount);
                    break;
                case 2:
                    cout<<"\nMaximum withdrawl limit is 25,000/-";
                    cout<<"\nEnter amount to withdraw: ";
                    cin>>amount;
                    sa.withdraw(amount);
                    break;
                case 3:
                    cout<<"\nTotal available balance: ";
                    sa.display();
                    break;
                case 4: 
                    cout<<"\nCheck balance in your account";
                    sa.check_min_bal();
                    break;   
                case 5:
                    cout<<"\nExit";
                    exit(0);
                    break;
                default:
                    cout<<"\nYou entered wrong choice";
                    break;
            }
        }
        else 
        {
            cout<<"\nCurrent Account";
            cout<<"\nEnter 1 to Deposit amount\nEnter 2 to Withdraw amount\nEnter 3 to display Balance\nEnter 4 to Check Balance\nEnter 5 to Exit";
            cout<<"\nEnter your choice: ";
            cin>>choice;
            switch(choice)
            {
                 case 1:
                    cout<<"\nEnter amount to deposit: ";
                    cin>>amount;
                    ca.deposit(amount);
                    break;
                case 2:
                    cout<<"\nMaximum withdrawl limit is 25,000/-";
                    cout<<"\nEnter amount to withdraw: ";
                    cin>>amount;
                    ca.withdraw(amount);
                    break;
                case 3:
                    cout<<"\nTotal available balance: ";
                    ca.display();
                    break;
                case 4:
                   cout<<"\nCheck balance in your account";
                   ca.check_min_bal();
                   break;     
                case 5:
                    cout<<"\nExit";
                    exit(0);
                    break;
                default:
                    cout<<"\nYou entered wrong choice";
                    break;
            }
        }
    }
    return 0;
}