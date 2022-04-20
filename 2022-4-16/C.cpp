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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


const int MAXN = 1e5 + 10;
class Solution {
public:
	int a[MAXN], d[MAXN], b[MAXN];
	int i = 1;
	
	void dfs(TreeNode* root){
		if(not root) return;

		dfs(root->left);
		a[i++] = root->val;
		dfs(root->right);

	}

	void build(int s, int t, int p) {
	  // 对 [s,t] 区间建立线段树,当前根的编号为 p
	  if (s == t) {
	    d[p] = a[s];
	    return;
	  }
	  int m = s + ((t - s) >> 1);
	  // 移位运算符的优先级小于加减法，所以加上括号
	  // 如果写成 (s + t) >> 1 可能会超出 int 范围
	  build(s, m, p * 2), build(m + 1, t, p * 2 + 1);
	  // 递归对左右区间建树
	  d[p] = d[p * 2] + d[(p * 2) + 1];
	}

	void update(int l, int r, int c, int s, int t, int p) {
	  if (l <= s && t <= r) {
	    d[p] = (t - s + 1) * c, b[p] = c;
	    return;
	  }
	  int m = s + ((t - s) >> 1);
	  if (b[p]) {
	    d[p * 2] = b[p] * (m - s + 1), d[p * 2 + 1] = b[p] * (t - m),
	          b[p * 2] = b[p * 2 + 1] = b[p];
	    b[p] = 0;
	  }
	  if (l <= m) update(l, r, c, s, m, p * 2);
	  if (r > m) update(l, r, c, m + 1, t, p * 2 + 1);
	  d[p] = d[p * 2] + d[p * 2 + 1];
	}

	int getsum(int l, int r, int s, int t, int p) {
	  if (l <= s && t <= r) return d[p];
	  int m = s + ((t - s) >> 1);
	  if (b[p]) {
	    d[p * 2] = b[p] * (m - s + 1), d[p * 2 + 1] = b[p] * (t - m),
	          b[p * 2] = b[p * 2 + 1] = b[p];
	    b[p] = 0;
	  }
	  int sum = 0;
	  if (l <= m) sum = getsum(l, r, s, m, p * 2);
	  if (r > m) sum += getsum(l, r, m + 1, t, p * 2 + 1);
	  return sum;
	}
    int getNumber(TreeNode* root, vector<vector<int>>& ops) {
    	memset(a, 0, sizeof(a));
    	memset(b, 0, sizeof(b));
    	memset(d, 0, sizeof(b));
    	i = 1;
    	dfs(root);
    	int len = i - 1;
    	build(1, len, 1);

    	for(auto &operation : ops){
    		int from = operation[1], to = operation[2];
    		int l = 1, r = len, al, ar;
    		if(from > a[len] or to < a[1]) continue;
    		while(l <= r){
    			int mid = (l+r) >> 1;
    			if(a[mid] >= from){
    				al = mid;
    				r = mid - 1;
    			}else l = mid + 1;
    		}
    		l = 1, r = len;
    		while(l <= r){
    			int mid = (l+r) >> 1;
    			if(a[mid] <= from){
    				ar = mid;
    				l = mid + 1;
    			}else r = mid - 1;
    		}
    		update(al, ar, operation[0], 1, len, 1);
    	}
    	int ans = 0;
    	for(int i = 1; i <= len; i++){
    		if(getsum(i, i, 1, len, 1) == 1) ans++;
    	}
    	return ans;
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}