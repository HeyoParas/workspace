#include<iostream>
using namespace std;
class box
{
    protected:
    double width,height,depth;
    public:
    box(double w,double h,double d)
    {
        width = w;
        height = h;
        depth = d;
    }
    void display()
    {
        cout<<"box called";
    }
};
class boxweight : public box
{
    protected:
    double weight;
    public:
    boxweight(double w,double h,double d,double wt):box(w,h,d)
    {
        weight = wt;
    }
    void display()
    {
        cout<<"boxweight called";
    }
};
class boxshipment : public boxweight
{
    protected:
    double boxes;
    public:
    boxshipment(double w,double h,double d,double wt,double n):boxweight(w, h, d ,wt)
    {
        boxes = n;
    }
    void display()
    {
        cout<<"boxshipment called";
    }
};
int main()
{
    boxshipment ob1(10,20,30,10,10);

    return 0;
}