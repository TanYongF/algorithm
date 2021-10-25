#include <iostream>
#include <cstring>
using namespace std;
class Employee
{
	protected:
		string name;   //姓名
		int working_years;   //工龄
	public:
		Employee(string nm="unnamed",int wy=0){
			name = nm;
			working_years = wy;
		}
		string Getname(){
			return name; 	
		}
		double ComputePay(){
			return 35 * working_years;
		}    //求工龄工资，就是：工龄*35
		void SetWorkyears(int wy){
			working_years = wy;
		}
};
class Worker : public Employee{
	private:
		double pay_per_hour;  //每小时工资额
		int work_time;             //当月工作时数
	public:
		Worker(string nm, int wy, int wt){
			name = nm;
			working_years = wy;
			work_time = wt;
		}
		double count_pay(){
			return pay_per_hour * work_time + ComputePay();

		}           //计算工资，按上面说明的计算规则
		void SetWorktime(int wt){
			work_time = wt;
		}   //设置当月工作时数
		void Setpay_per_hour(int x){
			pay_per_hour = x;
		}  //设置每小时工资额

};
class SalesPerson : public Employee{
	private:
		double pay_per_hour;   //每小时工资额
		double saleroom;       //当月售出商品金额
		int work_time;         //当月工作时数
	public:
		SalesPerson(string nm, int wy, double sr, int wt){
			name = nm;
			working_years = wy;
			saleroom = sr;
			work_time = wt;
		}
		double count_pay(){
			return pay_per_hour * work_time + saleroom * 0.01 + ComputePay();
		}      //计算工资，按上面说明的计算规则
		void SetWorktime(int wt){
			work_time = wt;
		}     //设置当月工作时数
		void Setpay_per_hour(int x){
			pay_per_hour = x;
		}  //设置每小时工资额
		void Setsalesroom(double sr){
			saleroom = sr;
		} //设置当月售出商品金额
};
class Manager : public Employee{
	public:
		Manager(string nm,int wy){
			name = nm;
			working_years = wy;
		}
		double count_pay(){
			return 1000 + ComputePay();
		}    //计算工资，按上面说明的计算规则


};
int main()
{
	Worker work("zhangqiang",3,200);
	work.Setpay_per_hour(50);
	cout<<"工资="<<work.count_pay()<<endl;
	work.SetWorktime(180);
	work.SetWorkyears(10);
	work.Setpay_per_hour(30);
	cout<<work.Getname()<<"  "<<work.count_pay()<<endl;
	SalesPerson sales("wangjun",5,300000,25);
	sales.SetWorktime(40);
	sales.Setpay_per_hour(80);
	sales.Setsalesroom(450000);
	cout<<sales.Getname()<<"  "<<sales.count_pay()<<endl;



	Manager mana("sunchao",20);
	cout<<mana.Getname()<<"  "<<mana.count_pay()<<endl;
	return 0;
}