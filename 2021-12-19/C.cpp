#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
    	int len = prices.size();
    	long long dp[len];
    	memset(dp, 0, sizeof(dp));
    	dp[0] = 1;
    	long long ans = 1;
    	for(int i = 1; i < len; i++){
    		if(prices[i] == prices[i-1] + 1){
    			dp[i] = dp[i-1] + 1;
    			ans = ans + dp[i];
    		}
    	}        
    	return ans;
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}