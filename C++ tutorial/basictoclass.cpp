// #include<iostream>
// using namespace std;
// class sample
// {
//     int a,b;
//     public:
//     sample(int x,int y=0)
//     {
//         a=x;
//         b=y;
//     }
//     void show()
//     {
//         cout<<"a="<<a<<endl;
//         cout<<"b="<<b<<endl;
//     }
// };
// int main()
// {
//     int x=10;
//     sample s1=x;
//     s1.show();
//     return 0;
// }

// #include<iostream>
// using namespace std;
// class sample
// {
//     int a,b;
    
//     public:
//     sample(int x,int y=0)
//     {
//         a=x;
//         b=y;
//     }
//     operator int()
//     {
//         return a*b;
//     }
//     void show()
//     {
//         cout<<"a="<<a<<endl;
//         cout<<"b="<<b<<endl;
//     }

// };
// int main()
// {
//     sample s1(50,10);
//     int x=s1;
//     s1.show();
//     cout<<"x="<<x<<endl;
//     return 0;
// }

// #include<iostream>
// using namespace std;
// class item
// {
//     public:
//      int a,b;
//     item(int x,int y)
//     {
//         a=x;
//         b=y;
//     }
//     void show()
//     {
//         cout<<"a="<<a<<endl;
//         cout<<"b="<<b<<endl;
//     }
// };
// class sample
// {
//     int m,n;
//     public:
//     sample(item i1)
//     {
//         m=i1.a;
//         n=i1.b;
//     }
//     void show()
//     {
//         cout<<"m="<<m<<endl;
//         cout<<"n="<<n<<endl;
//     }
// };
// int main()
// {
//     item i1(10,20);
//     i1.show();
//     sample s1=i1;
//     s1.show();
//     return 0;
// }

#include<iostream>
using namespace std;
class sample
{
    int m;
    public:
    void show()
    {
        cout<<"m="<<m<<endl;
    }
    
};
class item
{
    public:
    int a,b;
    item(int x,int y)
    {
        a=x;
        b=y;
    }
    void show()
     {
         cout<<"a="<<a<<endl;
         cout<<"b="<<b<<endl;
     }
    operator sample()
    {
        return (a*b);
    }
};

int main()
{
    item i1(10,20);
    i1.show();
    sample s1=i1;
    s1.show();
    return 0;
}