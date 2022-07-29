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
 typedef pair<TreeNode*, pair<int,int>> P;
class Solution {
public:
    vector<vector<int>> ans;
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<P> nodes;
        queue<P> q;
        q.push({root, {0, 0}});
        while(not q.empty()){
            auto front = q.front();
            TreeNode*  node = front.first;
            int curCol = front.second.second, curRow = front.second.first;
            q.pop();
            nodes.push_back({node, {curRow, curCol}});
            if(node->left) q.push({node->left, {curRow+1, curCol-1}});
            if(node->right) q.push({node->right, {curRow + 1, curCol + 1}});
        }
        sort(nodes.begin(), nodes.end(), [&](auto &p1, auto p2)->bool{
            int r1 = p1.second.first, c1 = p1.second.second, r2 = p2.second.first, c2 = p2.second.second;
            if(r1 == r2 and c1 == c2){
                return p1.first->val < p2.first->val;
            }else if(c1 == c2) return r1 < r2;
            else return c1 < c2;
        });
        vector<int> item;
       	int col = -1;
        for(auto it : nodes){
            if(it.second.second != col){
                if(not item.empty()) ans.push_back(item);
                item.clear();
                col = it.second.second;
            }
            item.push_back(it.first->val);
        }
        if(not item.empty()) ans.push_back(item);
        return ans;
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}