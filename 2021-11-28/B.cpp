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
    vector<int> getAverages(vector<ll>& nums, int k) {
    	int len = nums.size();
    	for(int i = 1; i < nums.size(); i++){
    		nums[i] = nums[i] + nums[i-1];
    	}
    	if(k == 0) return nums;
    	nums.insert(nums.begin(), 0);
    	 vector<int> ans;
    	for(int i = 1; i <= len; i++){
    		int s = i - k - 1, e = i + k;
    		if(s >= 0 and e <= len) ans.push_back((nums[e] - nums[s]) / (2 * k + 1)); 
    		else ans.push_back(-1);
    	}

    	return ans;
        
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}