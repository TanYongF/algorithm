#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <string>
#include <cstring>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <ctime>
#include <vector>
#include <fstream>
#include <list>
#include <iomanip>
#include <numeric>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s) memset(s, 0, sizeof(s))
const int inf = 0x3f3f3f3f;

int T;
ll n,k;
ll res =0;
map<ll,ll> mp;
ll cal(ll n, ll k){
	if(mp.find(n) != mp.end()) return mp[n];
	if(n <= k){
		mp[n] = 1;
		return 1;
	} 
	return mp[n] = cal(n/2,k) + cal(n - (n/2),k) + 1;
}
int main(int argc, char * argv[]){
	cin >> T;
	while(T--){
		scanf("%lld %lld", &n, &k);
		printf("%lld\n",cal(n, k));
		mp.clear();
	}


	/* code */


    return 0;
}