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
	vector<vector<int>> mp;
	int xx[4] = {0, 1, 0, -1}, yy[4] = {1, 0, -1, 0}, m, n;
	int check(int cx, int cy, vector<vector<int>> &matrix){
		//get cache
		if(mp[cx][cy] != -1) return mp[cx][cy];
		int ans = 0;
		for(int i = 0; i < 4; i++){
			int nx = cx + xx[i], ny = cy + yy[i];
			if(nx >= 0 and nx < m and ny >= 0 and ny < n and matrix[nx][ny] > matrix[cx][cy]){
				ans = max(ans, check(nx, ny, matrix));
			} 
		}
		return mp[cx][cy] = ans;
	}
    int longestIncreasingPath(vector<vector<int>>& matrix) {
       	m = matrix.size(), n = matrix[0].size();
        mp = vector<vector<int>>(m, vector<int>(n, -1));
        int ans = 0;
        for(unsigned i = 0; i < m; i++){
        	for(unsigned j = 0; j < n; ++j) {
        		ans = check(i, j, matrix);
        	}
        }
        return ans;
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}