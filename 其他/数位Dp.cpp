#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
ll dp[50][2530][50];//第i位，当前数模2520，最小公倍数 
int Hash[2530];
int a[50];
int Max = 2520;
//将可能最小公倍数数的所有可能情况映射在hash表中 也就是可以被2520整除
void init(){
	int cns = 0;
	for(int i = 1 ; i <= 2520; i++){
		if(Max % i == 0){
			Hash[i] = cns++;
		}
	}
}
//求最大公因数
ll gcd(ll a, ll b){
	if(!b) return a;
	else  return gcd(b, a % b);
}
ll dfs(int pos, int num, int lcm, int limit){
	if(pos == -1) return num % lcm == 0 ? 1 : 0;
	ll &now = dp[pos][num][Hash[lcm]];
	if(!limit && now != -1) return now;
	int max_a = limit ? a[pos] : 9;
	ll result = 0;
	for(int i = 0; i <= max_a; i++){
		result += dfs(pos-1, (num * 10 + i) % 2520, (i == 0 ? lcm : (lcm * i)/gcd(lcm,i)), (limit == 1 && i == max_a));
	}
	if(!limit) now = result;
	return result;
}
ll solve(ll n){
	int pos = 0;
	while(n){
		a[pos++] = n % 10;
		n /= 10;
	}
	return dfs(pos-1, 0, 1, 1);

}

int main(){
	init();
    int t;
    cin >> t;
    memset(dp,-1,sizeof(dp));
    while(t--){
        ll l,r;
        cin >> l >> r;
        cout << solve(r) - solve(l-1) << endl;
    }
    return 0;
}