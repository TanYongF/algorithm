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


class Solution {
public:
    int maxProfit(vector<int>& prices) {
    	int len = prices.size(), dp[len][4];
    	memset(dp, 0, sizeof(0));
    	dp[0][0] = -prices[0];
    	for(int i = 1; i < len; i++){
    		dp[i][0] = max(dp[i-1][0], max(dp[i-1][3], dp[i-1][1])-prices[i]);
    		dp[i][1] = max(dp[i-1][1], dp[i-1][3]);
    		dp[i][2] = dp[i-1][0]+prices[i];
    		dp[i][3] = dp[i-1][2];
    	}
    	return max(dp[len-1][1], max(dp[len-1][2], dp[len-1][3]));


    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}