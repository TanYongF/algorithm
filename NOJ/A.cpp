//https://acm.njupt.edu.cn/contest/136/board/challenge/A
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
const ll maxn(5010);
ll mod;
ll Jc[maxn];
ll Stirling[maxn][maxn];
void initS() {
    Stirling[0][0] = 0;
    Stirling[1][1] = 1;
    for(ll i = 2; i < maxn; i++) {
        for(ll j = 1; j <= i; j++) {
            Stirling[i][j] = (Stirling[i - 1][j - 1] + (j * Stirling[i - 1][j])%mod)%mod;
        }
    }
}

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
ll A(ll a, ll b){
	return Jc[a]* niYuan(Jc[a - b], mod) % mod;
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
int main(int argc, char * argv[]){
	int n,m;
	ll ans = 0;
	cin >> n >> m >> mod;
	initS();
	calJc();
	// cout << Stirling[3][2];
	for(int i=1; i<=m;i++){
		// cout << A(n,i) << " " << Stirling[m][i] << " " << i << endl;
		ans = (ans + A(n, i)%mod*Stirling[m][i]%mod*i%mod)%mod;
	}
	cout << ans;
    return 0;
}