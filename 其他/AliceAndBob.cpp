#include <iostream>
#include <math.h>
using namespace std;
int n;

int gcd(int i, int j){
	if(j == 0) return i;
	return gcd(j, i % j);
}
int main(){
	cin >> n;
	int cur = 0;
	cin >> cur;
	int maxValue = cur;
	for(int i = 1; i < n; i++){
		int temp = 0;
		cin >> temp;
		maxValue = max(maxValue, temp);
		cur = gcd(temp, cur);
	}
	int result = maxValue/cur-n;
	if(result % 2 == 0){
		cout << "Bob" << endl;
	}else{
		cout << "Alice" << endl;
	}
	return 0;




}