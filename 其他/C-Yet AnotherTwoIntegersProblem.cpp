#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
ll a, b;
int main(){
	int res = 0;
	int cur = std::abs(a -b);
	res = (cur / 10) + (cur == 0) ? 0 : 1;
	cout << res;
	return 0;
}
