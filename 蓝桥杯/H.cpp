#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long MAXN = 501;
ll ret = 0;
int mod = 1000000007;
void dfs(int n, int m, ll ans, int pre){
	if(n == 0 and m == 0 and ans == 0 and pre == 1){
		ret = (ret + 1) % mod;
		return;
	}
	if(m == 0 and n != 0) return;
	if(ans > m) return;  
	if(ans < 0) return;
	if(n < 0 or m < 0) return;
	if(n >= 1) dfs(n-1, m, ans * 2, 0);
	if(m >= 1 and ans > 0) dfs(n, m-1, ans-1, 1);
}
int main(){
	int n, m;
	cin >> n >> m;
	dfs(n, m, 2, -1);
	cout << ret;

	return 0;
}