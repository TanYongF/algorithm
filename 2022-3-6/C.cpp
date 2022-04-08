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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
    	unordered_map<int, vector<int>> mp;
    	unordered_map<int, int> inD;
    	for(auto &description : descriptions){
    		int parent = description[0], child = description[1], isLeft = description[2];
    		inD[description[child]]++;
    		if(not mp.count(parent))   mp[parent] = vector<int>(2, -1);
    		if(isLeft) mp[parent][0] = child;
    		else mp[parent][1] = child;
    	}
    	queue<TreeNode*> q;
    	for(auto &it : inD){
    		if(it.second == 0) q.push(new TreeNode(it.first));
    	}
    	TreeNode* head = q.front();
    	while(not q.empty()){
    		TreeNode* cur = q.front();
    		if(mp[cur->val].size() == 0) continue;
			if(mp[cur->val][0] != -1){
				TreeNode* leftt = new TreeNode(mp[cur->val][0]);
				cur->left = leftt;
				q.push(leftt);
			}
			if(mp[cur->val][1] != -1){
				TreeNode* rightt = new TreeNode(mp[cur->val][1]);
				cur->right = rightt;
				q.push(rightt);
    		}
    	}
    	return head;    
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}