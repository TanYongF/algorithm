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
    vector<int> maxScoreIndices(vector<int>& nums) {
    	int n = nums.size();
    	vector<int>  z(n,0), o(n,0);
    	for(int i = 0; i < n; i++){
    		if(i) z[i] =  z[i-1];
    		z[i] += (nums[i] ? 0 : 1);
    	}
    	for(int i = n - 1; i >= 0; i--){
    		if(i != n-1) o[i] = o[i+1];
    		o[i] += (nums[i] ? 1 : 0);
    	}
    	vector<int> ans;
    	int maxx = INT_MIN;
    	for(int i = 0; i <= n; i++){
    		int zero = (i == 0 ? 0 : z[i-1]), one = (i == n ? 0 : o[i]);
    		if(zero + one > maxx){
    			maxx = zero + one;
    			ans = vector<int>();
    			ans.push_back(maxx);
    		}else if(zero+one == maxx) ans.push_back(zero + one);
    	}
    	return ans;
        
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}