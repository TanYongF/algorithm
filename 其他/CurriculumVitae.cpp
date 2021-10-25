#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int getmax(int a,int b)
{if(a>b)return a;else return b;}
int nums[101];
int dp[101][2];
int main(){
	int num;
	cin >> num;
	for (int i = 1; i <= num; ++i)
	{
		scanf("%d", &nums[i]);
	}
	dp[0][0] = dp[0][1] = 0;
	for (int i = 1; i <= num; ++i)
	{
		if(nums[i] == 0){
                dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
                dp[i][1] = dp[i - 1][1] + 1;
		}else{
                dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]) + 1;
                dp[i][1] = dp[i - 1][1];
		}
	}
	        cout << max(dp[num][0], dp[num][1]) << endl;
	return 0;
}