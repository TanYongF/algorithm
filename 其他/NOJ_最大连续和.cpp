#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int INT_MIN = -2147483648;
	int n;		//定义行数
	int m;		//定义各行的个数
	cin >> n;
	int result[1000];
	for(int i = 0; i < n; i++){
		cin >> m;
		int nums[m];		//用来存储这一行的数
		for(int j = 0; j < m; j++){
			cin >> nums[j];
		}
		int dp[m]; //定义以第i个元素结尾的最大值
		for(int q = 0; q < m; q++){
			dp[q] = INT_MIN;
		}
		dp[0] = nums[0];
		int temp = dp[0];
		for(int k = 1; k < m; k++){
			dp[k] = max(nums[k], dp[k-1] + nums[k]);
			temp = max(temp, dp[k]);
		}
		result[i] = temp;
	}
	for(int i = 0; i < n; i++){
		cout << result[i] << endl;
	}
	return 0;
}