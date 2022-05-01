#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
int main(){
	int a, b, m , n;
	cin >> a >> b >> m >> n;
	if(m < a and n < a){
		cout <<  m << "-N" << " " << n << "-N" << endl;
		cout << "zhang da zai lai ba";
	}else if(m < a and n >= a and n < b){
		cout << m << "-N" << " " << n << "-Y" << endl;
		cout << 2 << ": huan ying ru guan" << endl;
	}else if(m < a and n >= b){
		cout <<  m << "-Y" << " " << n << "-Y" << endl;
		cout << "qing " << 2 <<" zhao gu hao " << 1 << endl;
	}else if(m >= a and m < b and n < a){
		cout <<  m << "-Y" << " " << n << "-N" << endl;
		cout << 1 << ": huan ying ru guan" << endl;
	}else if(m >=a and m < b and n >= a and n < b){
		cout <<  m << "-Y" << " " << n << "-Y" << endl;
		cout << "huan ying ru guan";
	}else if(m >= a and m < b and n >= b){
		cout <<  m << "-Y" << " " << n << "-Y" << endl;
		cout << "huan ying ru guan";
	}else if(m >= b and n < a){
		cout <<  m << "-Y" << " " << n << "-Y" << endl;
		cout << "qing " << 1 <<" zhao gu hao " << 2 << endl;
	}else if(m >= b and n >= a and n < b){
		cout <<  m << "-Y" << " " << n << "-Y" << endl;
		cout << "huan ying ru guan";
	}else{
		cout <<  m << "-Y" << " " << n << "-Y" << endl;
		cout << "huan ying ru guan";
	}
	return 0;
}