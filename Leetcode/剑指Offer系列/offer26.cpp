//https://leetcode-cn.com/problems/shu-de-zi-jie-gou-lcof/
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
	bool res = true;
    bool isSubStructure(TreeNode* A, TreeNode* B) {
    	if(!B) return false; 


    }
    void dfs(TreeNode* A, TreeNode* B){
    	if(!A || res) return;
    	dfs(A->left, B);
    	if(A->val == B->val) {
    		check(A,B);
    		return;
    	} 
    	dfs(A->right, B);
    }
    void check(TreeNode* A, TreeNode * B){
    	if(!A && B) {res= false; return;}
    	else if(A && !B) return;
    	else if(A && B){
    		check(A->left, B->left);
    		if(A->val != B->val ){res = false; return;}
    		check(A->right, A);
    	}

    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}