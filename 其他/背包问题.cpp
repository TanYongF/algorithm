#include <iostream>
#include <cstring>
using namespace std;
int N, W;
int dp[101][10001];
int weight[101], value[101];
int main(){
	cin >> N >> W;
	for (int i = 1; i <= N; ++i)
	{
		scanf("%d %d",&weight[i], &value[i]);
	}
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= W ; j++)
		{
			if(j < weight[i]) dp[i][j] = dp[i-1][j];
			else dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i]] + value[i]);
		}
	}
	cout << dp[N][W];
	return 0;
}