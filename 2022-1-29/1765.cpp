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
    int xx[4] = {0,-1,0,1}, yy[4] = {1, 0, -1, 0};
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size(), n = isWater[0].size();
        vector<vector<int>> ans(m, vector<int>(n, -1));
        queue<vector<int>> q;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(isWater[i][j] == 0){
                    ans[i][j] = 0;
                    q.push({i, j, 0});
                }
            }
        }
        while(not q.empty()){
            vector<int> &cs = q.front();
            q.pop();
            int cx =  cs[0], cy = cs[1], cl = cs[2];
            for(int i = 0; i < 4; i++){
                int nx = xx[i] + cx, ny = yy[i] + cy;
                if(nx >= 0 and nx < m and ny >= 0 and ny < n and ans[nx][ny] == -1){
                    ans[nx][ny] = cl + 1;
                    q.push({nx, ny,  cl + 1});
                }
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