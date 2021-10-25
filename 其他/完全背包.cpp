#include <iostream>
using namespace std;
int N , M;
int dp[101][50001];
int weight[101];
int value[101];
int main(){
	cin >> N >> M;
	for (int i = 1; i <= N; ++i)
	{
		scanf("%d %d", &weight[i], &value[i]);
	}
	for (int i = 1; i <= N ; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			if(j < weight[i]) dp[i][j] = dp[i-1][j];
			else dp[i][j] = max(dp[i][j-weight[i]] + value[i], dp[i-1][j]);
		}
	}
	cout << dp[N][M];
}