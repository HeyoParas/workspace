//multi level inheritance
#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
class Staff
{
    char name[20];
    int code;
    public:
        void initialise()
        {
            cout<<"\nEnter your name: ";
            cin.get();
            cin.getline(name,20);
            cout<<"\nEnter the code: ";
            cin>>code;
        }
        void show()
        {
            cout<<"\nName= "<<name<<"\tCode= "<<code<<endl;
        }
};
class Teacher:public Staff
{
    string subject,publication;
    public:
        void initialise()
        {
            Staff::initialise();
            cout<<"\nEnter the subject: ";
            cin.get();
            getline(cin,subject);
            cout<<"\nEnter the publicaton: ";
            getline(cin,publication);
        }
        void show()
        {
            Staff::show();
            cout<<"\nSubject= "<<subject<<"\tPublication= "<<publication<<endl;
        }
};
class Typist:public Staff 
{
    int speed;
    public:
        void initialise()
        {
            Staff::initialise();
            cout<<"\nEnter your Speed: ";
            cin>>speed;
        }
        void show()
        {
            Staff::show();
            cout<<"\nSpeed= "<<speed<<endl;
        }
};
class Regular:public Typist 
{
    double salary;
    public:
        void initialise()
        {
            Typist::initialise();
            cout<<"\nEnter your salary: ";
            cin>>salary;
        }
        void show()
        {
            Typist::show();
            cout<<"\nSalary= $"<<salary<<endl;
        }
};
class Casual:public Typist  
{
    float daily_wages;
    public:
        void initialise()
        {
            Typist::initialise();
            cout<<"\nEnter your Daily Wages: ";
            cin>>daily_wages;
        }
        void show()
        {
            Typist::show();
            cout<<"\nDaily wages= $"<<daily_wages<<endl;
        }
};
class Officer:public Staff  
{
    char grade;
    public:
        void initialise()
        {
            Staff::initialise();
            cout<<"\nEnter your Grade: ";
            cin>>grade;
        }
        void show()
        {
            Staff::show();
            cout<<"\nGrade= "<<grade<<endl;
        }
};
int main()
{
    Teacher t;
    Regular re;
    Casual ca;
    Officer ob;
    int choice,ch;
    while(1)
    {
        cout<<"\nEnter 1 for Teacher\nEnter 2 for Typist\nEnter 3 for Officer\nEnter 4 to Exit";
        cout<<"\nEnter your choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"\nEnter Data for Teacher";
                t.initialise();
                cout<<"\nTeacher Details";
                t.show();
                break;
            case 2:
                cout<<"\nTypist Details";
                cout<<"\nEnter 1 for Regular Typist\nEnter 2 to Casual Typist"<<endl;
                cin>>ch;
                if(ch==1)
                {
                    cout<<"\nEnter Data for Regular Typist";
                    re.initialise();
                    cout<<"\nRegular Typist Details";
                    re.show();
                }
                else if(ch==2)
                {
                    cout<<"\nEnter Data for Casual Typist";
                    ca.initialise();
                    cout<<"\nCasual Typist Details";
                    ca.show();
                }
                else 
                {
                    cout<<"\nYou entered wrong choice";
                }
                break;
            case 3:
                cout<<"\nEnter Data for Officer";
                ob.initialise();
                cout<<"\nOfficer Details";
                ob.show();
                break;
            case 4:
                cout<<"\nExit";
                exit(0);
                break;           
            default:
                cout<<"\nYou entered wrong choice";
                break;
        }
    }
    return 0;
}