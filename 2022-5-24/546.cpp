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
    int removeBoxes(vector<int>& boxes) {
    	int len = boxes.size();
    	int ans = 0;
    	vector<int> dp(len, 0);
    	while(not boxes.empty()){
    		int maxLen = -1 , maxIdx = -1;
    		dp = vector<int>(len, 0);
    		for(int i = 0; i < (int)boxes.size(); i++){
    			dp[i] = 1;
    			if(i and boxes[i-1] == boxes[i]) dp[i] += dp[i-1];
    			if(dp[i] > maxLen){
    				maxLen = dp[i];
    				maxIdx = i;
    			}
    		}
    		ans += maxLen * maxLen;
    		boxes.erase(boxes.begin() + maxIdx - maxLen + 1 , boxes.begin() + maxIdx + 1);
    	}
    	return ans;
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}