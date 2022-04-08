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
	int m, n, start_x, start_y;
	int x[4] = {0,1,0,-1}, y[4] = {-1, 0, 1, 0}; 
	vector<vector<int>> dis;
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
	    m = grid.size(), n = grid.size();
	    int high = pricing[1], low = pricing[0];
	    start_x = start[0], start_y = start[1];
	    dis = vector<vector<int>>(m, vector<int>(n, -1));
	    dis[start_x][start_y] = 0;
	    queue<pair<int,int>> q;
	    q.push({start_x, start_y});
	    while(not q.empty()){
	    	auto &[cur_x, cur_y] = q.front();
	    	q.pop();
			for(int i = 0; i < 4; i++){
				int next_x = cur_x + x[i], next_y = cur_y + y[i];
				if(next_x >= 0 and next_x < m  and next_y >= 0 and next_y < n and dis[next_x][next_y] == -1){
					if(grid[next_x][next_y] == 0) continue;
					dis[next_x][next_y] = dis[cur_x][cur_y] + 1;
					q.push({next_x, next_y});
				}
			}
	    }
	    vector<pair<int,int>> ans;
	    for(int i = 0; i < m; i++) for(int j = 0; j < n; j++) if(grid[i][j] != 0 and grid[i][j] <= high and grid[i][j] >= low) ans.push_back({i,j});
	    sort(ans.begin(), ans.end(), [&](pair<int,int> &p1, pair<int,int> &p2)->bool {
	    	int x1 = p1.first, y1 = p2.second, x2 = p2.first, y2 = p2.second;
	    	if(dis[x1][y1] != dis[x2][y2]) return dis[x1,y1] < dis[x2,y2];
	    	else{
	    		if(grid[x1][y1] != grid[x2][y2]) return grid[x1][y1] < grid[x2][y2];
	    		else{
	    			if(x1 != x2) return x1 < x2;
	    			else{
	    				if(y1 != y2) return y1 < y2;
	    				else return true;
	    			}
	    		} 
	    	}
	    	return false;
	    });
	vector<vector<int>> ret;
	// int num = 0;
	for(auto it : ans){
		if((int)ret.size() >= k) break;
		vector<int> v = {it.first, it.second};
		ret.push_back(v);
	}
	return ret;
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}