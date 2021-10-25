//https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/submissions/
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <string>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <climits>
#include <vector>
#include <iostream>
#include <list>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;


// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//     	int len = prices.size();
//     	int dp[len][2];
//     	memset(dp, 0, sizeof(dp));
//     	dp[0][0] = 0;
//     	dp[0][1] = -prices[0];
//     	for(int i = 1; i < len; i++){
//     		dp[i][0] = max(dp[i-1][0], dp[i-1][1]+prices[i]);
//     		dp[i][1] = max(dp[i-1][1], dp[i-1][0]-prices[i]);
//     	}
//     	return dp[len-1][0];
 
//     }
// };

class Solution {
public:
    int maxProfit(vector<int>& prices) {
    	int len = prices.size();
    	int ans= 0;
    	for(int i =1; i < len; i++){
    		ans += max(prices[i] - prices[i-1], 0);
    	}
    	return ans;
 
    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}