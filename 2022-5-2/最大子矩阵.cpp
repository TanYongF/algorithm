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
    vector<int> getMaxMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), ret = INT_MIN;
        vector<int> ans;
        for(int r1 = 0; r1 < m; r1++){
        	vector<int> nums(n, 0);
        	for(int r2 = 0; r2 < m; r2++){
        		int dp = 0, start;
        		for(int j = 0; j < n; j++){
        			nums[j] += matrix[r2][j];
        			if(dp > 0){
        				dp += nums[j];
        			}else{
        				dp = nums[j];
        				start = j;
        			}
        			if(dp > ret){
        				ret = dp;
        				ans = {r1, start, r2, j};
        			}
        		}		
        	}
        }
        return ans;
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	vector<vector<int>> test = {{9,-8,1,3,-2},{-3,7,6,-2,4},{6,-4,-4,8,-7}};
	s.getMaxMatrix(test);
	/* code */


    return 0;
}