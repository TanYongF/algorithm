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
	bool ans = false;
	int vis[101][101][205];
	int m, n;
	void dfs(vector<vector<char>>& grid, int x, int y, int left, int right){
		if(ans) return;
		if(right > left or left > (m+n-1)/2 or vis[x][y][left-right]){
			vis[x][y][left-right] = true;
			return;
		}
		if(x == m-1 and y == n-1){
			if(left == right) ans = true;
			return;
		}

		if(x + 1 < m){
			if(grid[x+1][y] == ')'){
				dfs(grid, x + 1, y, left, right + 1);
			}
			else{
				dfs(grid, x + 1, y, left + 1, right);
			} 
		}
		if(y + 1 < n){
			if(grid[x][y+1] == ')'){
				dfs(grid, x, y + 1, left, right + 1);
			} 
			else dfs(grid, x, y + 1, left + 1, right);
		}

	}
    bool hasValidPath(vector<vector<char>>& grid) {
    	m = grid.size(), n = grid[0].size();
    	memset(vis, 0, sizeof(vis));
    	if((m + n) % 2 == 0) return false;
    	if(grid[0][0] == ')') return false;
    	if(grid[m-1][n-1] == '(') return false;
    	dfs(grid, 0, 0, 1, 0);
    	return ans;
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}