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
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
    	int len = piles.size();
    	int dp[len+1][k+1];
   		int v[2005][2005], w[2005][2005], s[2005];
    	int n = len, m = k;
    	for(int i = 0; i < piles.size(); i++){
    		s[i+1] = piles.size();
    		for(int j = 0; j < piles[i].size(); j++){
    			v[i+1][j] = j+1;
    			w[i+1][j] = piles[i][j];
    			if(j) w[i+1][j] += w[i+1][j-1];
    		}
    	}
    	for(int i = 1; i <= n; i++){
    		for(int j = 0; j <= m; j++){
    			dp[i][j] = dp[i-1][j];
    			for(int k = 0; k < s[i]; k++){
    				if(j >= v[i][k]){
    					dp[i][j] = max(dp[i][j], dp[i-1][j-v[i][k]] + w[i][k]);
    				}
    			}
    		}
    	}
    	return dp[n][m];
        
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}