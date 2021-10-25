//https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/
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
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	unordered_map <int, TreeNode*> mp; 
	unordered_map <int, int> dept; 
	void getfather(TreeNode * root, int curdept){
		if(!root) return;
		// if(!root.right && !root.left) return;
		 getfather(root->left, curdept + 1);
		 dept[root->val] = curdept;
		if(root->left)  mp[root->left->val] = root;
		if(root->right) mp[root->right->val] = root;
		getfather(root->right, curdept + 1);
	}
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    	getfather(root, 0);
    	int dep_p = dept[p->val], dep_q = dept[q->val];
    	while(dep_p >= 0 && dep_q >= 0){
    		if(dep_p > dep_q){
    			p = mp[p->val];
    			dep_p--;
    		}else{
    			q = mp[q->val];
    			dep_q--;
    		}
    		if(q == p) return q;
    	}
    	return root;
        
    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}