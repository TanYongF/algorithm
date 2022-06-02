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
	int xx[4] = {0, -1, 0, 1}, yy[4] = {1, 0, -1, 0};
	int m , n;
	vector<vector<bool>> hasVisted;
	//get the steps 
	int bfs(vector<vector<int>>& forest, int sx, int sy, int tx, int ty){
        hasVisted = vector<vector<bool>>(m, vector<bool>(n, false));
        if(sx == tx and sy == ty) return 0;
		int step = 0;
		queue<pair<int,int>> q;
		q.push({sx, sy});
		hasVisted[sx][sy] = true;
		while(not q.empty()){
			step++;
			int size = q.size();
			while(size--){
				auto [cx, cy] = q.front();
				q.pop();
				for(int i = 0; i < 4; i++){
					int nx = xx[i] + cx, ny = yy[i] + cy;
					if(nx >= 0 and nx < m and ny >= 0 and ny < n and not hasVisted[nx][ny] and forest[nx][ny] != 0){
						hasVisted[nx][ny] = true;
						q.push({nx, ny});
						if(nx == tx and ny == ty) return step;
					}
				}
			}

		}
		return -1;
	}
    int cutOffTree(vector<vector<int>>& forest) {
    	m = forest.size(), n = forest[0].size();
    	int ans = 0;
    	int cx = 0, cy = 0;
    	vector<pair<int,int>> trees;
    	for(int i = 0; i < m; i++){
    		for(int j = 0; j < n; j++){
    			if(forest[i][j] > 1) trees.push_back({i, j});
    		}
    	}
    	sort(trees.begin(), trees.end(), [&](pair<int,int> p1, pair<int,int> p2)-> bool{
    		return forest[p1.first][p1.second] < forest[p2.first][p2.second];
    	});
        

    	for(int i = 0; i < trees.size(); i++){
    		int needStep = bfs(forest,cx, cy,trees[i].first, trees[i].second);
    		if(needStep == -1) return -1;
    		ans += needStep;
    		cx = trees[i].first;
    		cy = trees[i].second;
    	}
        return ans;
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}