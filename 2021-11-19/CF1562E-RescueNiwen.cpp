#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;
const int MAXN = 5005;
int lcp[MAXN][MAXN], dp[MAXN];
int T, n;
string s;
int larger(int i, int j){
	return (lcp[i][j] != n - i and  s[i + lcp[i][j]] > s[j + lcp[i][j]]);
}
int main(int argc, char * argv[]){
	cin >> T;
	while(T--){
		cin >> n >> s;
		// memset(lcp, 0, sizeof(lcp));
		for(int i = 0; i <= n; i++) for(int j = 0; j < n; j++) lcp[i][j] = 0;
		for(int i = n-1; i >= 0; i--){
			for(int j = n-1; j >= 0; j--){
				if(i == j) lcp[i][j] = 1;
				else if(s[i] == s[j]) lcp[i][j] = lcp[i+1][j+1] + 1;
			}
		}
		int ans = n;
		dp[0] = n;
		for(int i = 1; i < n; i++){
			dp[i] = n - i;
			for(int j = 0; j < i; j++){
				if(larger(i, j)) dp[i] = max(dp[i], dp[j]+ n-i - lcp[i][j]);
			}
			ans = max(ans, dp[i]);
		}
		cout << ans << endl;
	}
    return 0;
}