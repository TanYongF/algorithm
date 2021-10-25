#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <string>
#include <cstring>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <ctime>
#include <climits>
#include <vector>
#include <iostream>
#include <fstream>
#include <list>
#include <iomanip>
#include <numeric>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;

class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
    	if(maxMove == 0) return 0;//为了特判maxMove==0的时候
        long long ans = 0, dp[m+2][n+2][maxMove];//到达i,j移动k次的路径个数
    	int MOD = 1e9+7;

    	//初始化步骤
    	for(int i = 0; i < m+2; ++i) 
    		for(int j = 0; j < n+2; ++j) 
    			memset(dp[i][j], 0, sizeof(dp[i][j]));

    	//计算结果,注意递推的时候dp要取模下相加
    	dp[startRow+1][startColumn+1][0] = 1;
    	for(int k = 1; k < maxMove; k++)
    		for(int i = 1; i <= m; ++i) 
				for(int j = 1; j <= n; ++j)
				    dp[i][j][k] = (dp[i-1][j][k-1]%MOD + dp[i+1][j][k-1]%MOD + dp[i][j-1][k-1]%MOD + dp[i][j+1][k-1]%MOD) % MOD;	 

		//边界求和,注意四个角分别有两种移出方向,所以我们不需要考虑重复情况,直接首行末尾行,首列末尾列相加就好, 还有就是最大步骤是maxMove-1
     	for(int k = 0; k < maxMove; k++){
			for(int j = 1; j <= n; ++j)  ans = (ans%MOD + dp[1][j][k]%MOD + dp[m][j][k]%MOD)%MOD;
			for(int i = 1; i <= m; ++i)  ans = (ans%MOD + dp[i][1][k]%MOD + dp[i][n][k]%MOD)%MOD;    			
    	}
        
    	return ans;
    }
};
int main(int argc, char * argv[]){


	Solution s = Solution();
	cout << s.findPaths(36,5,50,15,3);
	/* code */


    return 0;
}