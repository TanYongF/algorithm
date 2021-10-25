#include <iostream>
#include <cstring>
using namespace std;
class Product
{
       string name;
       double price;
       Date deptime;
       string factory;
       bool easy_break;
       Date valtime; 
       string color;
       double high;
public: 
	Product(name, )
	SetProduct(name, price, deptime, factory, easy_break, valtime, color, high){
		this -> name = name;
		this -> price = price;
		this -> deptime = deptime;
		this -> factory = factory;
		this -> easy_break = easy_break;
		this -> valtime = valtime;
		this -> color = color;
		this -> high = high;
	}
    void output (); 
};
void Product::output (  )
{
       cout<<name<<" "<<price<<endl;
       cout<<deptime.Getyear()<<"-"<<deptime.Getmonth()<<"-"<<deptime.Getday()<<endl;
       cout<<factory<<" "<<easy_break<<endl;
       cout<<valtime.Getyear()<<"-"<<valtime.Getmonth()<<"-"<<valtime.Getday()<<endl;
}
int main()
{
       string  s;
       cin>>s;
       Product p1("car");
       Product p2("glass",3.00);
       Product p3("pen",5.00,2009,3,14);
       p1.SetProduct("car",100000.0,2009,3,14,"nanjing",0,2010,10,14,"red",1.5);
       p1.output();
       p2.output();
       p3.output();
       return 0;
}