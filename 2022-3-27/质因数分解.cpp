#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;

int main(int argc, char * argv[]){
	ll n, ans;
	cin >> n;
	for(ll i = 2; i * i <= n; i++){
		while(n % i == 0){
			n /= i;
			ans = n;
		}
		if(n == 1) break;
	}
	cout << ans;
    return 0;
}