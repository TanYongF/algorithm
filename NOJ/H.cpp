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
const int MAXN = 1e5+10;
int T;
int oneSize[MAXN], zeroSize[MAXN];
ll pow2[MAXN];

const ll maxn(100005), mod(1e9 + 7);
ll Jc[maxn];
void calJc()    //求maxn以内的数的阶乘
{
    Jc[0] = Jc[1] = 1;
    for(ll i = 2; i < maxn; i++)
        Jc[i] = Jc[i - 1] * i % mod;
}
//费马小定理求逆元
ll pow(ll a, ll n, ll p)    //快速幂 a^n % p
{
    ll ans = 1;
    while(n)
    {
        if(n & 1) ans = ans * a % p;
        a = a * a % p;
        n >>= 1;
    }
    return ans;
}
ll niYuan(ll a, ll b)   //费马小定理求逆元
{
    return pow(a, b - 2, b);
}
ll C(ll a, ll b)    //计算C(a, b)
{
    return Jc[a] * niYuan(Jc[b], mod) % mod
        * niYuan(Jc[a - b], mod) % mod ;
}

ll binpowmod(ll a, ll b, ll mod){
	a = a % mod;
	long long res = 1 % mod;
	while(b > 0){
		if(b & 1){
			res = res * a % mod;
		}
		a = a * a % mod;
		b >>= 1;
	}
	return res;
}
void initTwo(){
	pow2[0]= 1;
	for(int i = 1; i < MAXN; i++){
		pow2[i] = pow2[i-1]%mod*2%mod; 
	}

}

int main(int argc, char * argv[]){
	initTwo();
	calJc();
		for(int i = 0; i < MAXN-10; i++){
			cout << 1;
		}

	cin >> T;
	string s;
	while(T--){
		cin >> s;
		ms(oneSize,0);
		ms(zeroSize,0);
		int len = s.length();

		for(int i = s.length()-1; i >= 0; i--){
			if(s[i] == '1') {
				oneSize[i] = oneSize[i+1]+1;
				zeroSize[i] = zeroSize[i+1];
			}
			else {
				zeroSize[i] = zeroSize[i+1] + 1;
				oneSize[i] = oneSize[i+1];
			}
		}
		// for(int i = 0; i < s.length(); i++){
		// 	cout << oneSize[i];
		// }
		// for(int i = 0; i < s.length(); i++){
		// 	cout << zeroSize[i];
		// }
		// cout << endl;
		ll ans= 0;
		for(int i = 0; i < s.length(); i++){
			if(s[i] == '0') continue;
			int lastZero = oneSize[i] - 1;
			// cout << "lastzero" << lastZero << endl;
			for(int j = 0; j <= lastZero; j++){
				ans = (ans + C((ll)lastZero,(ll)j)*pow2[j+zeroSize[i]]%mod)%mod;
			}
			// cout << "i: " << i << " " << ans << endl;;
		}
		cout << ans+1 << endl;
	}


    return 0;
}