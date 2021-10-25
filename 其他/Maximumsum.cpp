#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
using namespace std;
int dp[105][105];
int nums[105];
int main(){
	int num;
	cin >>num;
	for (int i = 1; i <= num; ++i)
	{
		cin >> nums[i];
	}
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= num ; ++i)
	{
		dp[i][i+2] = nums[i] * nums[i+1] * nums[i+2];
	}
	for (int length = 4; length <= num; ++length)
	{
		for (int i = 0; i <= num + 1 - length; ++i)
		{
			int j = i+ length - 1;
			dp[i][j] = INT_MAX;
			for (int k = i + 1; k < j; ++k)
			{
				dp[i][j] = min(dp[i][j] , dp[i][k] + dp[k][j] + nums[i] * nums[j] * nums[k]);
			}
		}
	}
	printf("%d\n",dp[1][num]);
	return 0;
}