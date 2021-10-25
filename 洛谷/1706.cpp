#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <string>
#include <cstring>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <ctime>
#include <vector>
#include <fstream>
#include <list>
#include <iomanip>
#include <numeric>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s) memset(s, 0, sizeof(s))
const int inf = 0x3f3f3f3f;

int n;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class TreeNode{
public:
	int val;
	TreeNode *left;
	TreeNode *right;
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
vector<bool> isV;
class Solution {
public:
    queue<TreeNode*> q;
    vector<int> grap[504];
    vector<int> ret;
    // const int m = 504;
    
    bool isV[504];
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    	memset(isV, false, sizeof(isV));
        buildGrap(root);
        int target_val = target->val;
        isV[target_val] = true;
        dfs(0, k, target_val); 
        return ret;
        
    }
    
    void buildGrap(TreeNode* root){
        q.push(root);
        while(!q.empty()){
        	root = q.front();
           	q.pop();
            if(root->left != NULL){
                grap[root->left->val].push_back(root->val);
                grap[root->val].push_back(root->left->val);
                q.push(root->left);
            }
            if(root->right != NULL){
                grap[root->right->val].push_back(root->val);
                grap[root->val].push_back(root->right->val);
                q.push(root->right);
            }
        }
    }
    void dfs(int deepth ,int k, int node){
        
        if(deepth == k){
            ret.push_back(node);
            return;
        }
        for(int i = 0; i < grap[node].size(); i++){
            if(!isV[grap[node][i]]){
                isV[node] = true;
                dfs(deepth+1, k , grap[node][i]);
            }
        }
    }
};

int main(int argc, char * argv[]){
	// isV[500] =false;
	isV.push_back(false);
	cout << isV[0];
	// cin >> n;
	// std::vector<int> v;
	// for(unsigned i = 1; i <=n; ++i) {
	// 	v.push_back(i);
	// }
	// do{
	// 	for(unsigned i = 0; i < n; ++i) {
	// 		printf("%5d",v[i]);
	// 	}
	// 	cout << endl;
	// }while(next_permutation(v.begin(), v.end()));
	// /* code */


    return 0;
}