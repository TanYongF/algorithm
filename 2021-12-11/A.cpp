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
    vector<int> maxSubsequence(vector<int>& nums, int k) {
    	vector<int> tem = nums;
    	sort(tem.begin(), tem.end(), greater<int>());
    	map<int,int> mp;
    	for(int i=  0; i < k; i++){
    		mp[tem[i]]++;
    	}
    	vector<int> ans;
    	for(int i = 0; i < nums.size(); i++){
    		// if(ans.size() == k) return;
    		if(mp[nums[i]] > 0){ ans.push_back(nums[i]); mp[nums[i]]--; }
    	}
    	return ans;
        
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}