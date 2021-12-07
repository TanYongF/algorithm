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


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<int, TreeNode*> fa;
    unordered_map<int, bool> vis;
    TreeNode *st, *de;
    string ans;
    bool flag = false;
    void dfs(TreeNode* root){
        if (root->left != nullptr) {
            fa[root->left->val] = root;
            dfs(root->left);
        }
        if (root->right != nullptr) {
            fa[root->right->val] = root;
            dfs(root->right);
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        fa[root->val] = nullptr;
        dfs(root);
        while (p != nullptr) {
            vis[p->val] = true;
            p = fa[p->val];
        }
        while (q != nullptr) {
            if (vis[q->val]) return q;
            q = fa[q->val];
        }
        return nullptr;
    }
    void get1(TreeNode *root,int startValue, int destValue){
    	if(not root) return;
    	get1(root->left,startValue, destValue);
    	if(root->val == startValue) st = root;
    	if(root->val == destValue) de = root;
    	get1(root->right, startValue, destValue);
    }
    void find(TreeNode *root, string str){
    	if(flag) return;
    	if(not root) return;
    	if(root == de){
    		ans += str;
    		flag = true;
    		return;
    	}
    	str.push_back('L');
    	find(root->left, str);
    	str.pop_back();

    	str.push_back('R');
    	find(root->right,str);
    	str.pop_back();
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
    	get1(root, startValue, destValue);
    	TreeNode* common = lowestCommonAncestor(root,st, de);
    	TreeNode *cur = st;
    	while(cur != common){
    		ans += "U";
    		cur = fa[cur->val];
    	}
    	find(common, "");
    	return ans;        
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}