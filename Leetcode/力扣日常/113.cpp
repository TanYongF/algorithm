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

class Solution {
public:
	vector<vector<int>> ans;
	vector<int> temp;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    	temp.push_back(root->val);
   		dfs(root, root->val ,targetSum);
   		return ans;

    }
    void dfs(TreeNode *root, int curLen, int &targetSum){
    	if(not root->left and not root->right and curLen==targetSum){
    		ans.push_back(temp);
    		return;
    	} 
    	if(root->left){
    		temp.push_back(root->left->val);
    		dfs(root->left, curLen + root->left->val, targetSum);
    		temp.pop_back();
    	}
    	if(root->right){
    		temp.push_back(root->right->val);
    		dfs(root->right, curLen + root->right->val, targetSum);
    		temp.pop_back();
    	}
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}