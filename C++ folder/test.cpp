//add two number using friend function
#include<iostream>
using namespace std;
class sample
{
   int a,b;
   public:
   sample()
   {
      a=10;
      b=20;
   }
   friend int sum(sample s1);
};
int sum(sample s1)
{
   return (s1.a+s1.b);
}
int main ()
{
   sample s1;
   int res=sum(s1);
   cout<<res;
    return 0;
}