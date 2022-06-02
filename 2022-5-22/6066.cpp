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
    int minimumLines(vector<vector<int>>& stockPrices) {
    	int len = stockPrices.size();
    	if(len <= 2) return 1;
    	int ans = 1;
    	for(int i = 1; i < len -1; i++){
    		int a1 = stockPrices[i-1][0] - stockPrices[i][0];
    		int b1 = stockPrices[i-1][1] - stockPrices[i][1];
    		int a2 = stockPrices[i][0] - stockPrices[i+1][0];
    		int b2 = stockPrices[i][1] - stockPrices[i+1][1];
    		if(a1 * b2 != a2 * b1) ans++;
    	}
    	return ans;
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}