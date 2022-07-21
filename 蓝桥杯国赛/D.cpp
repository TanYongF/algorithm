#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int ans = 0;

const int MAXN = 2e5+10;
string str;
void update(int i, int &a, int &b){
	int num = str[i] - '0';
	if(num < b){
		b = b - num - 1;
		num = 9;
	}else{
		int pre = num;
		if(num + a >= 9){
			num = 9;
		}else{
			num = num + a;
		}
		a -= (num - pre);
	}
	str[i] = num + '0';
}
int main(){
	int a, b;
	cin >> str >> a >> b;
	for(int i = 0; i < str.size(); i++){
		update(i, a, b);
	}
	cout << str;
	return 0;
}