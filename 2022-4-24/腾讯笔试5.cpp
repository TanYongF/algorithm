#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;

int T;
int main(int argc, char * argv[]){
	int n, m;
	cin >> n >> m;
	vector<int> price(n);
	for(int i = 0 ; i < n; i++) cin >> price[i];
	ll dp[n][n];
	//初始化
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++) 
			dp[i][j] = -1;

	//第0天为m
	dp[0][0] = m;
	if(m >= price[0]){
		dp[0][1] = m - price[0];
	}
	for(int i = 1; i < n; i++){
		for(int j = 0; j < n; j++){
			dp[i][j] = dp[i-1][j];
			//买一
			if(j > 0 and dp[i-1][j-1] != -1 and dp[i-1][j-1] >= price[j]){
				dp[i][j] = max(dp[i][j], dp[i-1][j-1] - price[i]);
			}
			//卖一
			if(j < n-1 and dp[i-1][j + 1] != -1){
				dp[i][j] = max(dp[i][j], dp[i-1][j+1] + price[i]);
			}
		}
	}
	ll ans = 0;
	for(int i = 0; i < n; i++){
		if(dp[n-1][i] == -1) continue;
		ans = max(ans, dp[n-1][i] + i * price[n-1]);
	}
	cout << ans;
    return 0;
}

