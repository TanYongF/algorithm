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
class Solution {
public:
    int pairSum(ListNode* head) {
    	vector<int> node;
    	ListNode* cur = head;
    	while(cur){
    		node.push_back(cur->val);
    	}
    	int ans= INT_MIN;
    	int len = node.size();
    	for(int i = 0; i <=  (len / 2) -1; i++){
    		ans=  max(node[i] +  node[len - 1 - i], ans);
    	}
    	return ans;
       
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}