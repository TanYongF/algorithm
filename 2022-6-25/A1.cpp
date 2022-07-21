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
    bool checkXMatrix(vector<vector<int>>& grid) {
    	bool ans = true;
    	int n = grid.size();
    	for(int i = 0; i < n; i++){
    		for(int j = 0; j < n; j++){
    			if(i == j or i + j == n-1){
    				if(grid[i][j] == 0){
    					return false;
    				} 
    			} else{
    				if(grid[i][j] != 0) return false;
    			}
    		}
    	}
    	return true;
        
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}