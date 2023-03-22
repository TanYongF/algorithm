#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;

int T;
int main(int argc, char * argv[]){
	cin >> T;
	vector<int> cost(T,0);
	for(int i = 0; i < T; i++) cin >> cost[i];
	vector<int> dp(T + 1, INT_MAX);
	dp[0] = 0;
	dp[1] = 0;
	for(int i = 2; i < T + 1; i++){
		dp[i] = min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2]);
	}
	cout <<  dp[T];
	return 0;
}