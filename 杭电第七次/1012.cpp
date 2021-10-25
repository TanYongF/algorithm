#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <stack>
#include <unordered_map>
#include <queue>
#include <set>
#include <map>
#include <ctime>
#include <climits>
#include <vector>
#include <iostream>
#include <fstream>
#include <list>
#include <iomanip>
#include <numeric>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;
const int MAXN = 1e5 + 10;
unordered_map<int, ll> mp(28);
int T;
ll MOD = 998244353;
ll item[MAXN];

int main(int argc, char * argv[]){
	cin >> T;
	ll ans = 0;
	while(T--){
		string str;
	    cin >> str;
		ms(item,0);
		ans = 0;
		mp.clear();

		int len = str.size();
		for(int i = 0; i < len; ++i){
			mp[str[i] - 'a']++;
		}
		cout << len << endl;
		for(int i = len-1; i >= 0; --i) {
			int curstr = str[i] - 'a';
			for(unsigned j = 0; j <= 25; ++j) {
				item[i] = (item[i] + (mp[j] * mp[j]) % MOD ) % MOD;
			}
			mp[curstr]--;
		}

		for(int i = str.length()-1; i >= 0; --i) {
			ans += ((item[i] % MOD) * (len - i)) % MOD;
		}
		cout << ans << endl;
	}


    return 0;
}