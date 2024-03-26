//multiple inheritance
#include<iostream>
using namespace std;
class TyreCompany  
{
	protected:
	    int stock;
	public:
		void setTyreStock(int stk)
		{
			stock=stk;
		}	
};
class IronCompany  
{
	protected:
	    int stock;
	public:
		void setIronStock(int stk)
		{
			stock=stk;
		}	
};
class PlasticCompany  
{
	protected:
	    int stock;
	public:
		void setPlasticStock(int stk)
		{
			stock=stk;
		}	
};
class CarManufacturer: public TyreCompany, public IronCompany, public PlasticCompany  
{
	int noOfCars;
	public:
		void manufactureCar(int n)
		{
			noOfCars=n;
		}	
		int isManufacturingPossible()
		{
			cout<<"Availability\n";
			cout<<"\nTyres: "<<TyreCompany::stock<<" tyres";
			cout<<"\nIron: "<<IronCompany::stock<<" KG";
			cout<<"\nPlastic: "<<PlasticCompany::stock<<" KG";
			if(TyreCompany::stock>=(noOfCars*4))
			{
				if(IronCompany::stock>=noOfCars*50)
				{
					if(PlasticCompany::stock>=noOfCars*30)
					{
						return 1;
					}
					else
					{
						cout<<"\nShortage of plastic";
						return 0;
					}
				}
				else
				{
					cout<<"\nShortage of iron";
					if(PlasticCompany::stock!=noOfCars*30)
					{
						cout<<"\nShortage of plastic also";
						return 0;
					}
				}
			}
			else
			{
				cout<<"\nShortage of tyres";
				if(IronCompany::stock>=noOfCars*50)
				{
					if(PlasticCompany::stock==noOfCars*30)
					{
						return 0;
					}
					else
					{
						cout<<"\nShortage of plastic";
						return 0;
					}
				}
				else
				{
					cout<<"\nShortage of iron";
					if(PlasticCompany::stock!=noOfCars*30)
					{
						cout<<"\nShortage of plastic also";
						return 0;
					}
				}
			}
		}
};
int main()
{
	CarManufacturer obj;
	obj.setTyreStock(10);  
	obj.setIronStock(200);  
	obj.setPlasticStock(50);
	int noOfCarsToManufacture;
	cout<<"Enter no. of cars to manufacture: ";
	cin>>noOfCarsToManufacture;
	obj.manufactureCar(noOfCarsToManufacture);
	int status=obj.isManufacturingPossible();
	if(status==1)
	{
		cout<<"\nYes manufacturing possible";
	}
	else
	{
		cout<<"\nManufacturing not possible due to above mentioned reason(s)";
	}
	return 0;
}