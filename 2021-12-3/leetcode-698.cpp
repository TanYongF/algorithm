//https://leetcode-cn.com/problems/partition-to-k-equal-sum-subsets/
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
	int k, len, sum, status, j, cur;
	bool flag = false;
	vector<int> vs;
	void check(int cn, int cs, int ci){
		// cout << cn <<  " " << cs << " " << ci << endl;
		if(cn == k){
			if(cs == (1 << len) - 1) flag = true;
			return;
		}
		if(ci == vs.size()) return;
		for(int i = ci; i < (int)vs.size() and not flag; i++){
			 if((vs[i] & cs) == 0) check(cn + 1, cs | vs[i], i + 1);
		}
	}
    bool canPartitionKSubsets(vector<int>& nums, int _k) {
        len = nums.size();
       	k = _k;
        sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % k) return false;
       	sum /= k;
  		for(int i = 1; i <  (1 << len) - 1; i++){
  			status = i;
  			j = 0, cur = 0;
  			while(status){
  				if(status & 1) cur += nums[j];
  				j++;
  				status >>= 1; 
  			}
  			// cout << i << " : " << cur << endl; 
  			if(cur == sum) vs.push_back(i);  
  		}
  		// for(auto it : vs) cout << it << " ";
  		check(0,0,0);
  		return flag;
    }
};

int main(int argc, char * argv[]){
	// vector<int> nums = {4,3,2,3,5,2,1};
	vector<int> nums = {213,321,3,1,4,4,15,1,51,5,5,15,15,23};
	Solution s = Solution();
	cout << s.canPartitionKSubsets(nums, 13);
	/* code */


    return 0;
}