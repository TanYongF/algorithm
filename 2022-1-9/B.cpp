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
    int minSwaps(vector<int>& nums) {
    	int len = nums.size(), ones = 0;
    	for(auto num : nums) if(num) ones++;
    	for(int i = 0; i < len; i++) nums.push_back(nums[i]);
    	for(int i = 1; i < nums.size(); i++) nums[i] += nums[i-1];
    	int maxx = INT_MIN;
    	for(int i = 0, j = 0; i < len;){
    		int cur = 0;
    		if(i == 0) cur = nums[i + ones - 1];
    		else cur = nums[i + ones - 1] - nums[i-1];
    		maxx = max(cur, maxx);
    	}
    	return ones-maxx;
       
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}