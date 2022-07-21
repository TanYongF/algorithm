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
    int xx[4] = {1, 0, -1, 0}, yy[4] = {0, 1, 0, -1};
    unordered_map<int, int> mp;
    int idx = -1, m, n, area = 0;
    void dfs(vector<vector<int>> &grid, int cx, int cy){
        area++;
        grid[cx][cy] == idx;
        for(int i = 0; i < 4; i++){
            int nx = cx + xx[i], ny = cy + yy[i];
            if(nx < m and nx >= 0 and ny < n and ny >= 0 and grid[nx][ny] == 1) dfs(grid, nx, ny);
        }
    }
    int largestIsland(vector<vector<int>>& grid) {
        mp[0] = 0;
        m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    area = 0;
                    dfs(grid, i, j);
                    mp[idx--] = area;
                } 
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                cout << grid[i][j] <<  " ";
            }
            cout << endl;
        }
        
        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] != 0) continue;
                unordered_map<int,int> can;
                if(i-1 >= 0) can[grid[i-1][j]] += mp[grid[i-1][j]];
                if(i+1 <  m) can[grid[i+1][j]] += mp[grid[i+1][j]];
                if(j-1 >= 0) can[grid[i][j-1]] += mp[grid[i][j-1]];
                if(j+1 <  n) can[grid[i][j+1]] == mp[grid[i][j+1]];
                int bindingArea = 0;
                for(auto it : can) bindingArea += it.second;
                ans = max(ans, bindingArea);
            }
        }
        return ans;
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	vector<vector<int>> test = {{1,0}, {0, 1}};
	return s.largestIsland(test);
	/* code */


    return 0;
}