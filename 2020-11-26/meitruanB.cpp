#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;

int T, n, m, k;
const int MAXN = 200;
int coins[MAXN][MAXN];
char colors[MAXN][MAXN];
int main(int argc, char * argv[]){
	cin >> n >> m >> k;
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> colors[i][j];
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> coins[i][j];
	int dp[MAXN][MAXN];	
	memset(dp, 0, sizeof(dp));
	int ans = 0;
	// for(int i = 0;  i < n; i++) for(int  j= 0; j < m; j++) dp[i][j] = -1;
	dp[0][0] = 0;
	// for(int j = 1; j < m; j++){
	// 	dp[i][j] = -1;
	// 	if(colors[])
	// 	if(dp[0][j-1] < 0) break;
	// 	if(colors[0][j] != colors[0][j-1]) dp[0][j] = dp[0][j-1] + coins[0][j] - k;
	// 	else dp[0][j] = dp[0][j-1] + coins[0][j];
	// 	ans = max(ans, dp[0][j]);
	// }
	// for(int i = 1; i < n; i++){
	// 	if(dp[i-1][0] < 0) break;
	// 	if(colors[i][0] != colors[i-1][0]) dp[i][0] = dp[i-1][0] + coins[i][0] - k;
	// 	else dp[i][0] = dp[i-1][0] + coins[i][0];
	// 	ans = max(ans, dp[i][0]);
	// }

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(i or j) dp[i][j] = -1;
			else continue;
			if(i > 0 and dp[i-1][j] >= 0){
				if(colors[i-1][j] == colors[i][j]) dp[i][j] = max(dp[i][j], dp[i-1][j] + coins[i][j]);
				else if(dp[i-1][j] >= k) dp[i][j] = max(dp[i][j], dp[i-1][j] + coins[i][j] - k);
			}

			// dp[i][j] = -1;
			if(j > 0 and dp[i][j-1] >= 0){
				if(colors[i][j-1] == colors[i][j]) dp[i][j] = max(dp[i][j], dp[i][j-1] + coins[i][j]);
				else if(dp[i][j-1] >= k) dp[i][j] = max(dp[i][j], dp[i][j-1] + coins[i][j] - k);

			}
			ans = max(ans, dp[i][j]);

		}
	}
	// for(int i = 0; i< n; i++){
	// 	for(int j = 0; j < m; j++){
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	cout << ans;

    return 0;
}