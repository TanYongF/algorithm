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
	unordered_map<int, int> mp;
    vector<int> recoverArray(vector<int>& nums) {
    	vector<int> v;
    	for(auto num : nums) mp[num] = 1;
    	for(int i = 0;i < nums.size(); i++){
    		ll cur = nums[i] - nums[0];
    		if(cur % 2 == 0) v.push_back(cur / 2); 
    	}
    	sort(nums.begin(), nums.end());
    	vector<int> ans;
    	for(auto k : v){
    		for(auto num : nums) mp[num] = 1;
    		bool ok = true;
    		for(int i = nums.size() -1; i >= 0; i--){
    			if(mp[nums[i]] == 1){
    				if(mp.find(nums[i] - k) == mp.end()){
    					ok = false;
    					break;
    				}else{
    					mp[nums[i]] = 0;
    					mp[nums[i] - k] = 0;
    				}
    			}
    		}
    		if(ok){
    			for(auto num : nums) mp[num] = 1;
   				for(int i = nums.size() -1; i >= 0; i--){
	    			if(mp[nums[i]] == 1){
	    				ans.push_back(nums[i] - k);
	    					mp[nums[i]] = 0;
	    					mp[nums[i] - k] = 0;
	    				}

    			}
    			return ans;
    		}
    	}
    	return {};
    }

    	
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}