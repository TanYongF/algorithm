#include <iostream>
#include <cstring>
using namespace std;
class Station{
protected:
	string from;
	string to;
public:
	Station(){};
	Station(string from, string to){
		this->from = from;
		this->to = to;
	}
	void disp(){
		cout << from << to;

	}
};
class Mile{
protected:
	double mile;
public:
	Mile(){};
	Mile(double mile){
		this -> mile = mile;
	}
	void disp(){
		cout << mile;
	}
};
class Price : public Mile, public Station{
protected:
	double price;
public:
	Price(string from, string to, double mile){
		this -> from = from;
		this -> to = to;
		this -> mile = mile;
		if(mile <= 3){
			price = 8;
		}else{
			price = 8 + (int)((mile - 3) / 0.5) * 0.7;
			if((int)((mile - 3)*10) % 5 != 0){
				price += 0.7;
			}
		}
	}
	void disp(){
		cout << from << " "<< to << " " << mile << " " << price;
	}
};
int main(){
	string from, to;
	double mile;
	cin >> from >> to >> mile;
	Price price = Price(from, to, mile);
	price.disp();
	return 0;
}