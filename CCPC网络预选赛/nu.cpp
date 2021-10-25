#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <string>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <climits>
#include <vector>
#include <iostream>
#include <list>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;
const int maxn = 100010;
ll mod = 998244353;
//快速幂
ll qpow(ll a,ll x){
    ll ret=1;
    while (x){
        if (x&1)
            ret = ret*a%mod;
        a=a*a%mod;
        x>>=1;
    }
    return ret;
}

string s;
ll as[maxn];
ll dp[maxn][10];
int main(int argc, char * argv[]){
	int T;
	string t = "nunhehheh";
	cin >> T;
	while(T--){
		memset(as, 0, sizeof(as));
		memset(dp, 0, sizeof(dp));
		cin >> s;
		ll ans = 0;
		int len = s.length();
		if(len <= 9){cout << 0 << endl; continue;}  
		as[0] = 0;
		for(int i = 1; i <= s.length(); i++) as[i] = as[i-1] + (s[i-1] == 'a' ? 1 : 0);
		dp[0][0] = 1;
		for(int j = 1; j <= 9; j++){
			long long sum1 = dp[0][j-1];
			for(int i = 1; i <= len; i++){
				if(s[i-1] == t[j-1]){
					dp[i][j] = sum1;
				}
				sum1 =(sum1 + dp[i][j-1]) % mod;
			}
		}
		// cout << dp[9][9] << endl;
		for(int i = 1; i <= len; i++){
			ans = (dp[i][9] * (ll)(qpow(2, (as[len]- as[i-1])) - 1)%mod + ans)%mod;
		}
		cout << ans << endl;
		/* code */
	}
    return 0;
}