//https://leetcode-cn.com/problems/recover-binary-search-tree/
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
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void recoverTree(TreeNode* root) {
    	TreeNode *pre, *x, *y;
    	stack<TreeNode*> st;
    	while(!st.empty() || !root){
    		//直接将左链全部添加
    		while(!root) {st.push(root->left), root = root->left;}
    		//当前需要遍历的就是栈顶元素
    		root = st.top();
    		st.pop();
    		//如果前一个节点的值大于当前节点的值, x有一种情况, 那么y有两种情况
    		if(!pre && pre -> val > root->val){
				y = root;
				if(!x) x = pre;
				else break;
    		}
    		pre = root;
    		//开始遍历右子树  
    		root = root->right;
    	}
    	swap(x,y);
    }
    void swap(TreeNode *root1, TreeNode *root2){
    	int temp = root1->val;
    	root1->val = root2->val;
    	root2->val = temp;
    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}