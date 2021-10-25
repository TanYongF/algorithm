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


// class Solution {
// public:
// 	int ans = 0 ;
//     int pathSum(TreeNode* root, int targetSum) {
//     	dfs(root, 0, targetSum);
//         dfs(root, root->val , targetSum);
//     	return ans;
//     }
//     void dfs(TreeNode *root, int curSum, int targetSum){
//         cout << curSum << endl;
//     	if(curSum == targetSum) ans++;
//     	//No
//         if(root->left){
//             dfs(root->left, 0, targetSum);
//             dfs(root->left, curSum + root->left->val, targetSum);
//         }else if(root -> right){
//             dfs(root->right,0, targetSum);
//             dfs(root->right, curSum + root->right->val, targetSum);
//         }
//     }
// 

class Solution {
public:
	unordered_map<int ,int> mp;
	int ans =0 ;
    int pathSum(TreeNode* root, int targetSum) {
    	mp[0] = 1;
    	getAns(root, root->val, targetSum);
    	return ans;

    }
    void getAns(TreeNode* node, int curLen, int targetSum){
    	int need = curLen - targetSum;
    	if(mp.find(need) != mp.end()) ans += mp[need];
    	mp[curLen]++;
    	if(node -> left) {
    		getAns(node->left, curLen+node->left->val, targetSum);
    	}
    	if(node->right){
    		getAns(node->right, curLen+node->right->val, targetSum);
    	}
    	mp[curLen]--;
    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}