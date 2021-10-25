#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
int a,b,c;
int main(){
	int res =0;
	cin >> a >> b >>c;
	res = max(a*b*c,res);
	res = max(res , a*(b+c));
	res = max(a + b + c,res);
	res = max(res, (a+b)*c);
	cout << res;
	return 0;
}