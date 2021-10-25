#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <string>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <stack>
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
ll a,b,n;
int T;
bool check(ll num,ll a,ll b){
	bool flag = true;
	while(num != 0){
		if(num % 10 == a || num % 10 == b) num /= 10;
		else return false;
	}
	return true;
}
const int maxn = 1000010;
ll mod = 1000000007;
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
ll fac[maxn],inv[maxn];
 
ll init(){
    fac[0]=1;
    for (int i=1;i<maxn;i++)
        fac[i]=fac[i-1]*i%mod;
    inv[maxn-1]=qpow(fac[maxn-1],mod-2);
    for (int i=maxn-2;i>=0;i--)
        inv[i]=inv[i+1]*(i+1)%mod;
    return 0;
}
 
ll c(ll n,ll m){
    if (n<m) return 0;
    return fac[n]*inv[m]%mod*inv[n-m]%mod;
}

int main(int argc, char * argv[]){
	init();
	cin >> a >> b >> n;

	ll ans = 0;
	for(int i = 0; i <= n; i++){
		 ll sum = i * a + (n-i) * b;
		 if(check(sum, a,b)) ans = (ans + c(n, i))%mod; 
	}
	cout <<ans; 
    return 0;
}