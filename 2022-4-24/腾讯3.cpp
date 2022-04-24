#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;

int T;
int main(int argc, char * argv[]){
	int n, len;
	string str;
	cin >> n >> str;
	len = n;
	vector<ll> attack(n+2, 0), protect(n+2, 0);
	for(int i = 1; i <= len; i++){
		attack[i] = attack[i-1];
		if(str[i-1] == '0') attack[i] += i;
	}

	for(int i = len; i >= 1; i--){
		protect[i] = protect[i+1];
		if(str[i-1] == '1') protect[i] += i;
	}
	ll ans, value = INT_MAX;
	for(int i = 0; i <= len; i++){
		ll cur = abs(attack[i] - protect[i+1]);
		if(cur < value){
			ans = i - 1;
			value = cur;
		}
	}
	cout << value;
    return 0;
}