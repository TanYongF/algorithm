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
typedef pair<int,int> P;
class Solution {
public:
	int x[4] = {0,1,0,-1}, y[4] = {1,0,-1,0};
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
    	int m = grid.size(), n = grid[0].size(), k = grid[row][col];
    	auto hasV = vector<vector<int>>(m, vector<int>(n, false));
    	queue<P> q;
    	hasV[row][col] = true;
    	bool flag = false;
    	q.push(make_pair(row,col));
    	while(not q.empty()){
    		flag = false;
    		P cur = q.front();
    		q.pop();
    		for(int i = 0; i < 4; i++){
    			int nex = cur.first + x[i], ney = cur.second + y[i];
    			if(nex >= 0 and nex < m and ney >= 0 and ney < n and not hasV[nex][ney]){
    				if(grid[nex][ney] == k) q.push(make_pair(nex, ney)); 
    				else flag = true;
    			}
    		}
    		if(flag) grid[cur.first][cur.second] = color;
    	}
    	for(auto it : grid){
    		for(auto itt : it) cout << itt << " ";
    			cout << endl;
    	}
    	return grid;

    }
};


int main(int argc, char * argv[]){

	Solution s = Solution();
	vector<vector<int>> te = {{1,2,2},{2,3,2}};
	s.colorBorder(te,0,1,3);
	/* code */


    return 0;
}