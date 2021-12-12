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
    long long subArrayRanges(vector<int>& nums) {
    	int len = nums.size();
    	int b[len][len], a[len][len];
    	for(int i = 0; i < len; i++){
    		int maxx = INT_MIN, minn = INT_MAX;
    		for(int j = i; j < len; j++){
    			maxx = max(maxx, nums[i]);
    			minn = min(minn, nums[i]);
    			a[i][j] = maxx;
    			b[i][j] = minn;
    		}
    	}
    	long long ans;
    	for(int i = 0; i < len; i++){
    		for(int j = i; j < len; j++){
    			ans += (a[i][j] - b[i][j]);
    		}
    	}
    	return ans;
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}