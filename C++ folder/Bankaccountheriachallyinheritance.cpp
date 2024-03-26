#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
class BankAccount
{
	char name[20],accType[10];
	long accNumber;
	protected:
	double balance;
	public:
		void initialise(char n[],long aN, char aT[],double bal)
		{
			strcpy(name,n);
			accNumber=aN;
			strcpy(accType,aT);
			balance=bal;
			cout<<"Welcome "<<n<<"\nBalance = "<<balance<<endl;
		}
		void deposit(double amt)
		{
			balance+=amt;
			displayBalance();
		}
		void withdraw(double amt)
		{
			if(balance<amt)
			{
				cout<<"Insufficient balance\n";
				cout<<"Transaction cancelled\n";
			}
			balance-=amt;
			displayBalance();
		}
		void displayBalance()
		{
			cout<<"Balance = "<<balance;
		}
};
class SavingAccount: public BankAccount
{
	public:
		void deposit(double amt)
		{
			BankAccount::deposit(amt);
		}
		int penalty(int amt)
		{
			if(balance-amt<5000)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		void withdraw(double amt)
		{
			if(amt<=10000)
			{
				if(penalty(amt))
				{
				cout<<"After withdrawl balance will be below minimum\n and";
				cout<<" because of that a penalty of Rs. 500 will be imposed\n";
				cout<<"Do you still want to continue<y/n>: ";
				char choice;
				cin>>choice;
				if(choice=='y'||choice=='Y')
				{
					BankAccount::withdraw(amt+500);//500 of penalty
				}
				else
				{
					cout<<"\nTransaction cancellled by user";
				}
			}
			else
			{
				BankAccount::withdraw(amt);
			}
		}
		else
			{
				cout<<"\nYou exceeds withdrawl limit of 10,000 Rs.";
			}
		}
};
class CurrentAccount: public BankAccount
{
public:
	void deposit(double amt)
	{
		BankAccount::deposit(amt);
	}
	int penalty(int amt)
	{
		if(balance-amt<10000)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
 	void withdraw(double amt)
	{
		if(amt<=50000)
		{
			if(penalty(amt))
			{
				cout<<"After withdrawl balance will be below minimum\n and";
				cout<<" because of that a penalty of Rs. 500 will be imposed\n";
				cout<<"Do you still want to continue<y/n>: ";
				char choice;
				cin>>choice;
				if(choice=='y'||choice=='Y')
				{
					BankAccount::withdraw(amt+1000);//1000 of penalty
				}
				else
				{
					cout<<"\nTransaction cancellled by user";
				}
			}
			else
			{
				BankAccount::withdraw(amt);
			}
		}
		else
			{
				cout<<"\nYou exceeds withdrawl limit of 50,000 Rs.";
			}
		}
};
int main()
{
	char accChoice;
	cout<<"Enter type of account\n";
	cout<<"Press s for saving or c for current account\n";
	cin>>accChoice;
	if(accChoice=='s'||accChoice=='S')
	{
		SavingAccount sa;
		sa.initialise("Ankit",1234567890123,"Saving",50000.0);
		double amount;
		int choice;
		while(1)
		{
			cout<<"\n\n1:Deposit\n2:Withdraw\n3:Display balance\n0:Exit\n";
			cout<<"Enter your choice: ";
			cin>>choice;
			switch(choice)
			{
				case 1:
					cout<<"Enter amount to deposit: ";
					cin>>amount;
					sa.deposit(amount);
					break;
				case 2:
					cout<<"Maximum withdrawl limit is 10,000/-";
					cout<<"Enter amount to withdraw: ";
					cin>>amount;
					sa.withdraw(amount);
					break;
				case 3:
					cout<<"Total available balance : ";
					sa.displayBalance();
					break;
				case 0:
					exit(0);
				default: 
					cout<<"Wrong choice";
			}	
		}	
	}
	else if(accChoice=='c'||accChoice=='C')
	{
		CurrentAccount sa;
		sa.initialise("Ankit",1234567890123,"Current",50000.0);
		double amount;
		int choice;
		while(1)
		{
			cout<<"\n\n1:Deposit\n2:Withdraw\n3:Display balance\n0:Exit\n";
			cout<<"Enter your choice: ";
			cin>>choice;
			switch(choice)
			{
				case 1:
					cout<<"Enter amount to deposit: ";
					cin>>amount;
					sa.deposit(amount);
					break;
				case 2:
					cout<<"Maximum withdrawl limit is 25,000/-";
					cout<<"Enter amount to withdraw: ";
					cin>>amount;
					sa.withdraw(amount);
					break;
				case 3:
					cout<<"Total available balance : ";
					sa.displayBalance();
					break;
				case 0:
					exit(0);
				default: 
					cout<<"Wrong choice";
			}	
		}	
	}
	else
	{
		cout<<"Wrong choice";
	}
	return 0;
}