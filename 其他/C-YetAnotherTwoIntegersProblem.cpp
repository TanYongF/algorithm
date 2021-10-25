#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
int T;
ll a, b;
int main(){
	cin >> T;
	while(T--){
		int res = 0;
		cin >> a >> b;
		int cur = std::abs(a -b);
		res = (cur / 10) + ((cur % 10 == 0) ? 0 : 1);
		cout << res << endl;
	}
	return 0;
}
