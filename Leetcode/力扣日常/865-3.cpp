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
typedef pair<TreeNode* , int> P;
class Solution {
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
    	return dfs(root).first;
    }
    P dfs(TreeNode *node){
    	if(not node) return make_pair(nullptr, 0);
    	P L = dfs(node->left), R = dfs(node->right);
    	if(L.second > R.second) return make_pair(L.first, L.second+1);
    	else if(L.second < R.second) return make_pair(R.first, R.second + 1);
    	return make_pair(node, L.second+1);

    } 
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}