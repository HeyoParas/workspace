//Hierarichal inheritance
#include<iostream>
#include<cstring>
using namespace std;
class sports
{
	int fees;
	char name[20];
	int a;
	char des[20];
	public:
	void getdata(char n[20],int f,int aa)
	{
		strcpy(name,n);
		a=aa;
		fees=f;
	}
	void display()
	{
		cout<<"Name:"<<name<<"\nAge:"<<a<<"\nYour coaching fees:"<<fees<<endl;
		cout<<"congratulations you now become part of our spectrum academy\n";
	}
	void team()
	{
		if(a<=18)
		{
			strcpy(des,"Junior");
			cout<<"Destination:"<<des<<endl;
		}
		else if(a>=18)
		{
			strcpy(des,"Senior");
			cout<<"Destination:"<<des<<endl;
		}
		
	}
};
class Hockey:public sports
{
	public:
	 void hockeyinfo(char n[20],int f,int a)
	 {
	 	getdata(n,f,a);
	 	display();
	 }
};
class Football:public sports
{
	public:
	void footballinfo(char n[20],int f,int a)
	{
		getdata(n,f,a);
	}
};
class Jrfootball:public Football
{
	public:
	void jrinfo(char n[20],int f,int a)
	{
		footballinfo(n,f,a);
		display();
		team();
	}

};
class Srfootball:public Football
{
	public:
	void srinfo(char n[20],int f,int a)
	{
		footballinfo(n,f,a);
		display();
		team();
	}
};
class Cricket:public sports
{
	public:
	void cricketinfo(char n[20],int f,int a)
	{
		getdata(n,f,a);
		display();
	}
};
int main()
{
	int ch,a;
	char n[20];
	char ca;
	cout<<"Welcome to our  spectrum sports coaching center\n";
	cout<<"Enter your name:\n";
	cin>>n;
	cout<<"Enter your age:\n";
	cin>>a;
	
	do
	{
        cout<<"\nChoose the sports you want to choose\n";
	    cout<<"1) Hockey\n2) Football\n3) Cricket\n4) Exit\n";
		cout<<"Enter the choice:\n";
		cin>>ch;
		switch(ch)
	   {
		case 1:
		cout<<"Fees for Hockey coaching for 1 year is Rs.30000\n ";
		cout<<"Do you want to continue: press <y/n>\n";
		cin>>ca;
		if(ca=='y'||ca=='Y')
		{
			Hockey h;
			h.hockeyinfo(n,30000,a);
		}
		else if(ca=='N'||ca=='n')
		{
			cout<<"Thank you for visiting here\n";
		}
		break;
		case 2:
		cout<<"Football teams further divided into:\n";
		cout<<"1) Junior football team\n2) Football team\n";
		if(a<=18)
		{
			cout<<"You are now in junior football team because your age is less than or equal to 18\n";
			cout<<"Fees for Football coaching for 1 year is Rs.50000\n ";
		    cout<<"Do you want to continue: press <y/n>\n";
		    cin>>ca;
		    if(ca=='y'||ca=='Y')
		     {
			   Jrfootball j;
		       j.jrinfo(n,50000,a);
		     }
		else
		{
			cout<<"Thank you for visiting here\n";
		}
		}
		else
		{
			cout<<"You are now in Senior football team because your age is greater than 18\n";
			cout<<"Fees for Football coaching for 1 year is Rs.60000\n ";
		    cout<<"Do you want to continue: press <y/n>\n";
		    cin>>ca;
		    if(ca=='y'||ca=='Y')
		    {
			  Srfootball s;
		      s.srinfo(n,60000,a);
	     	}
		else
		{
			cout<<"Thank you for visiting here\n";
		}
		}
		break;
		case 3:
		cout<<"Fees for Cricket coaching for 1 year is Rs.40000\n ";
		cout<<"Do you want to continue: press <y/n>\n";
		cin>>ca;
		if(ca=='y'||ca=='Y')
		{
			Cricket c;
		    c.cricketinfo(n,40000,a);
		}
		else
		{
			cout<<"Thank you for visiting here\n";
		}
		break;
		case 4:
		cout<<"Exit\n";
		break;
		Default:
		cout<<"Invalid choice\n";	
	}
}while(ch!=0);
 return 0;	
}