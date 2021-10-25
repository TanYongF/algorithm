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

class Solution {
public:
	int m, n;
	int dx[4] = {0,1,0,-1};
	int dy[4] = {1,0,-1,0};
	int ans = INT_MIN;
	void dfs(int x, int y, vector<vector<int>>& grid, int cur){
		ans = max(ans, cur);
		grid[x][y] = 0;
		for(int i= 0; i < 4; i++){
			int next_x = x + dx[i], next_y = y + dy[i];
			if(next_x >= 0 && next_x < m && next_y >= 0 && next_y < n && grid[next_x][next_y] == 1) 
				dfs(next_x, next_y, grid, cur+1);
		}

	}
    int maxAreaOfIsland(vector<vector<int>>& grid) {
    	m = grid.size(), n = grid[0].size();
    	for(int i = 0; i < m; i++)
    		for(int j = 0; j < n; j++)
    			if(grid[i][j] == 1) dfs(i,j, grid, 0);
    	return ans;
    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}