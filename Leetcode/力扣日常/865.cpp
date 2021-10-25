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
	unordered_map<TreeNode* , TreeNode*> father;
	unordered_map<TreeNode*, int> depth;
	int maxDeepth = INT_MIN;
	TreeNode* ret;
    void getFather(TreeNode *node, int curDepth){
    	if(not node) return;
    	getFather(node->left, curDepth + 1);
    	depth[node] = curDepth;
    	maxDeepth = max(maxDeepth, curDepth);
    	if(node->left) father[node->left] =  node;
    	if(node->right) father[node->right] = node;
    	getFather(node->right, curDepth + 1);
    }
    // void slove(TreeNode* root){
    // 	if(not root) return;
    // 	slove(root->left);
    // 	ret.push_back(root);
    // 	slove(root->right);
    // }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
    	getFather(root, 0);
    	father[root] = root;
    	vector<TreeNode*> maxNodes;
    	TreeNode* ret ;
    	for(auto node : depth) 
    		if(node.second == maxDeepth) 
    			maxNodes.push_back(node.first); 
    	while(1){
    		int flag = true;
    		ret = maxNodes[0];
    		maxNodes[0] = father[maxNodes[0]]; 
    		for(int i = 1; i < maxNodes.size(); i++){
    			if(maxNodes[i] != ret) flag = false;
    			 maxNodes[i] = father[maxNodes[i]];
    		}
    		if(flag) break;
    	}
    	return ret;
    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}