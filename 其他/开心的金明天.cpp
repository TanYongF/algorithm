#include <iostream>
using namespace std;
int N, K;
int value[26];
int good[26];
int dp[25][30001];
int main(){
	cin >> N >> K;
	for (int i = 1; i <= K; ++i)
	{
		scanf("%d %d", &value[i], &good[i]);
	}
	for (int i = 1; i <= K; ++i)
	{
		for (int j = 1; j <= N ; j++)
		{
			if(j < value[i]) dp[i][j] = dp[i-1][j];
			else dp[i][j] = max(dp[i-1][j], dp[i-1][j-value[i]] +value[i] * good[i]);
		}
	}
	cout << dp[K][N];
}