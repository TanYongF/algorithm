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

int ans = 0;
int dfs(TreeNode *root){
	if(not root) return 0; 
	int rmax = dfs(root->right);
	ans = max(ans, lmax + rmax + 1);
	return max(lmax, rmax) + 1; 
}
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
    	dfs(root);
    	return ans;
    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	 


    return 0;
}