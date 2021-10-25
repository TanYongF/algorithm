#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <string>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <climits>
#include <vector>
#include <iostream>
#include <bitset>
#include <list>
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


// class Solution {
// public:
// 	bool flag = false;
//     bool hasPathSum(TreeNode* root, int targetSum) {
//     	dfs(root, root->val, targetSum);
//     	return flag;
//     }
//     void dfs(TreeNode* root,int curLen, int targetSum){
//     	if(curLen == targetSum && not root->left && root->right){
//     		flag = true;
//     		return;
//     	} 
//     	if(root->left and not flag) dfs(root, curLen+ root->left->val, targetSum);
//     	if(root->left and not flag) dfs(root, curLen+ root->right->val, targetSum);
//     }
// };
class Solution {
public:
	bool flag = false;
    bool hasPathSum(TreeNode* root, int targetSum) {
    	dfs(root, 0, targetSum);
    	return flag;
    }
    void dfs(TreeNode* root,int curLen, int targetSum){
    	curLen += root->val;
    	if(not root->left and not root->right){flag = curLen == targetSum - curLen; return;}
    	dfs(root->left, curLen, targetSum);
    	dfs(root->right, curLen, targetSum);
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}