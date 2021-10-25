#include <iostream>
using namespace std;

class Box
{
	protected:
		double length;
		double heigth;

	public:
		double get(void){
			return length*heigth;
		}
		void set(double len, double hei){
			length = len;
			heigth = hei;
		}
		Box operator+(const Box& b){
			Box box;
			box.length = this -> length + b.length;
			box.heigth = this -> heigth + b.heigth;
			return box;
		}
};
class SmalleBox : public Box{
	private:
		double weigth;
	public:
		double get(void){
			return length*weigth*length;
		}
		void set(double len, double hei, double wei){
			length = len;
			weigth = wei;
			heigth = hei;
		}

};

int main(){

	Box b;
	Box b2;
	SmalleBox sb;
	b.set(1.2,2.4);
	b2.set(1.2,2.4);
	sb.set(1.2, 2.4, 3.6);
	Box boxThree = b + b2;
	double box_result = b.get();
	double Smalle_result = sb.get();
	cout << box_result << endl;
	cout << "SmalleBox:" << Smalle_result << endl;
	cout << boxThree.get() << endl;
	cout << "Hello World!" ;
	int n1;
	int n2;
	cin >> n1 >> n2;
	cout << n1 << n2;
	return 0;
}