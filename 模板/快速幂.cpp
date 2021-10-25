#include <stdio.h>
#include <iostream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;


//简单快速幂
long long res = 1;
/**
 * long long a : 基数
 * long long b : 幂级数
 * long long res : 结果
 **/
ll binpow(ll a, ll b){
	long long res = 1;
	while(b > 0){
		if(b & 1){
			res = res * a;
		}
		a *= a;
		b >>= 1;
	}
	return res;
}


//快速幂+取模
/**
 * long long a : 基数
 * long long b : 幂级数
 * long long m : 模
 * long long res : 结果
 **/
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

// int main(int argc, char * argv[]){
// 	ll res = binpowmod(1000000,1000000000,1000007);
// 	cout << res;
// 	/* code */


//     return 0;
// }

