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
const int MAXN = 1e9+10;
class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
    	// int len = nums;
    	long long ans = 0;
    	int ck = 0, j = 0;
    	set<int> st;
    	// sort(nums.begin(), nums.end());
    	for(auto &num : nums) st.insert(num);
    	int l = 0, r = MAXN, ret;
    	while(l <= r){
    		int mid = (l + r) >> 1;
    		int less = distance(st.begin(),st.upper_bound(mid));
    		// int less = ;
    		if(mid - less >= k){
    			ret = mid;
    			r = mid -1;
    		}else l = mid + 1;
    	}
    	ans = 1L *ret * (1 + ret) / 2;
    	for(auto &num : st){
    		if(num <= ret){
    			ans = ans - 1L*num;
    		}
    	}
    	return ans;
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	vector<int> v = {1,4,25,10,25};
	int k = 2;
	s.minimalKSum(v, k);
	/* code */


    return 0;
}