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
    int jump(vector<int>& nums) {
        int len = nums.size();
        int step = 0;
        int end = 0;
    	int maxPos = INT_MIN;
    	for(int i = 0; i < len - 1; i++){
    		maxPos = max(maxPos, i + nums[i]);
    		if(i == end){
    			end = maxPos;
    			step++;
    		}
    	}
        return step;
    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}