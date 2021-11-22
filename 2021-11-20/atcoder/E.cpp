#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;
// const 
int T;
// a^n mod を計算する
long long modpow(long long a, long long n, long long mod) {
  long long res = 1;
  while(n > 0) {
    if(n & 1)
      res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}
int main(int argc, char * argv[]){
	ll N, M, K;
	cin >> N >> K >> M;
	ll mod = 998244353;
	// N %= mod, M %= mod, K%=mod;
	if(M == mod) {cout << 0; return 0;}
	ll temp = modpow(K%(mod-1), N, mod-1);
	
	cout << modpow(M%mod, temp, mod);
    return 0;
}