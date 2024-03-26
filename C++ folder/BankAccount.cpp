                                             #include<iostream>
using namespace std;
class bankAccount
{
	char name[25];
	long acc_no;
	double balance;
	public:
		void initialize()
		{
			cout<<"Enter your Name: ";
			cin>>name;
			cout<<"\nEnter you Account Number ";
			cin>>acc_no;
			cout<<"\nEnter you Current Balance ";
			cin>>balance;
		}
		void deposit( double a)
		{
			balance=balance+a;
		}
		void withdraw(double a)
		{
			balance=balance-a;
		}
		void display()
		{
			cout<<name<<" "<<"Your Current balance is :"<<balance;
		}
};
class savingAccount:public bankAccount
{
	char pan[20],ch;
	public:
		void deposit(double a)
		{
			if(a>50000)
			{
				cout<<"Do you have a PAN card?\nPress Y for Yes or N for No\n";
				cin>>ch;
				if(ch=='Y')
				{
					cout<<"Please enter you PAN Card Number: ";
					cin>>pan;
					bankAccount::deposit(a);
				}
				else
				{
					cout<<"You cannot make a Deposit because the limit is Exceeded";
				}
			}
			else 
			{
				bankAccount::deposit(a);
			}
		}
		void withdraw(double a)
		{
			if(a<=25000)
			{
				bankAccount::withdraw(a);
			}
			else
			{
				cout<<"You are not allowded to withdraw more than 25000 at once\n";
			}
		}
};
int main()
{
	savingAccount obj;
	int ch=1;
	double a;
	while(ch!=0)
	{
		cout<<"\n1) Enter details\n2) Deposit Amount\n3) Withdraw Amount\n4) Display\n0 ) Exit\n";
		cout<<"Enter your choice ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"Enter your details :\n";
				obj.initialize();
				break;
			case 2:
				cout<<"Enter the amount to Deposit :\n";
				cin>>a;
				obj.deposit(a);
				break;
			case 3:
				cout<<"Enter the amount to Withdraw :\n";
				cin>>a;
				obj.withdraw(a);
				break;	
			case 4:
				obj.display();
				break;
			case 0:
				cout<<"Exit\n";
				break;
			default:
					cout<<"Invalid choice\n";
		}
	}
}