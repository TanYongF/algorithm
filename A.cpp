#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;

int T;
int main(int argc, char * argv[]){
	long long n, x;
	string s;
	cin >> n >> x;
	cin >> s;
	vector<int> v;
	while(x){
		v.push_back(x & 1);
		x = x >> 1;
	}
	reverse(v.begin(), v.end());
	for(auto &ch : s){
		if(ch == 'U') v.pop_back();
		if(ch == 'L') v.push_back(0);
		if(ch == 'R') v.push_back(1);
	}
	reverse(v.begin(), v.end());
	unsigned long long power = 1, ans = 0;
	for(auto bit : v){
		ans += power * bit;
		power = power * 2; 
	}
	cout << ans;

    return 0;
}