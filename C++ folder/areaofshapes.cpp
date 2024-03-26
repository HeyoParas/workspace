#include<iostream>
#include<stdlib.h>
#define pi 3.14
using namespace std;
class shapes
{
    protected:
    int res;
    
    public:
    void circle(int radius)
    {
        res= pi*radius*radius;
    }
    void square(int side)
    {
        res=side*side;
    }
    void triangle(int base,int height)
    {
        res=(base*height)/2;
    }
    void sphere(int radius)
    {
        res=4*pi*radius*radius;
    }
    void cube(int side)
    {
        res=6*side*side;
    }
    void tetrahedral(int side)
    {
        res=1.44*side*side;
    }
};
class two_D:public shapes
{
    protected:

    public:
};
class three_D:public shapes
{
    protected:

    public:
};
class circle:public two_D
{
    protected:
    int radius;
    public:
    void input()
    {
        cout<<"enter the radius of the circle :";
        cin>>radius;
    }
    void area()
    {
        shapes::circle(radius);
    }
    void display()
    {
        cout<<"area of the circle is:"<<res<<endl;
    }
};
class square:public two_D
{
    protected:
    int side;
    public:
    void input()
    {
        cout<<"enter the side of the square :";
        cin>>side;
    }
    void area()
    {
        shapes::circle(side);
    }
    void display()
    {
        cout<<"area of the sqaure is:"<<res<<endl;
    }
};
class triangle:public two_D
{
    protected:
    int base;
    int height;
    public:
    void input()
    {
        cout<<"enter the base of the triangle :";
        cin>>base;
        cout<<"enter the height of the triangle :";
        cin>>height;
    }
    void area()
    {
        shapes::triangle(base,height);
    }
    void display()
    {
        cout<<"area of the triangle is:"<<res<<endl;
    }
};
class sphere:public three_D
{
    protected:
    int radius;
    public:
    void input()
    {
        cout<<"enter the radius of the sphere :";
        cin>>radius;
    }
    void area()
    {
        shapes::sphere(radius);
    }
    void display()
    {
        cout<<"area of the sphere is:"<<res<<endl;
    }
};
class cube:public three_D
{
    protected:
    int side;
    public:
    void input()
    {
        cout<<"enter the side of the cube :";
        cin>>side;
    }
    void area()
    {
        shapes::cube(side);
    }
    void display()
    {
        cout<<"area of the cube is:"<<res<<endl;
    }
};
class tetrahedral:public three_D
{
    protected:
    int side;
    public:
    void input()
    {
        cout<<"enter the side of the tetrahedral :";
        cin>>side;
    }
    void area()
    {
        shapes::tetrahedral(side);
    }
    void display()
    {
        cout<<"area of the terahedral is:"<<res<<endl;
    }
};
int main()
{
    int ch;
    int op;
    while(1)
    {
        cout<<"which type of shape you want ?\n1. 2-dimensional\n2. 3-dimensional\n3. Exit"<<endl;
        cout<<"enter your choice:";
        cin>>ch;
        switch(ch)
        {
            case 1:
            cout<<"what type of shape you want?\n";
            cout<<"1. circle\n";
            cout<<"2. square\n";
            cout<<"3. triangle\n";
            cout<<"4. exit\n";
            cout<<"enter your choice:";
            cin>>op;
            switch(op)
            {
                case 1:
                circle c1;
                c1.input();
                c1.area();
                c1.display();
                break;

                case 2:
                square s1;
                s1.input();
                s1.area();
                s1.display();
                break;

                case 3:
                triangle t1;
                t1.input();
                t1.area();
                t1.display();
                break;

                case 4:
                exit;
                
                default :
                cout<<"invalid choice\n";
                break;
            }

            case 2:
            cout<<"what type of shape you want?\n";
            cout<<"1. sphere\n";
            cout<<"2. cube\n";
            cout<<"3. tetrahedral\n";
            cout<<"4. exit\n";
            cout<<"enter your choice:";
            cin>>op;
            switch(op)
            {
                case 1:
                sphere s1;
                s1.input();
                s1.area();
                s1.display();
                break;

                case 2:
                cube c1;
                c1.input();
                c1.area();
                c1.display();
                break;

                case 3:
                tetrahedral t1;
                t1.input();
                t1.area();
                t1.display();
                break;

                case 4:
                exit;
                
                default :
                cout<<"invalid choice\n";
                break;

            }

            case 3:
            exit;
            break;
            
            default:
            cout<<"invaild choice\n";
            break;
        }

    }

    return 0;
}
