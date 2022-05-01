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
    int m, n;
    int xx[4] = {0, 1, 0, -1}, yy[4] = {1, 0, -1, 0};
    vector<vector<int>> heights;
    vector<vector<bool>> hasV;
    map<pair<int,int>, bool> mp;
    bool can(int x, int y){
        if(mp.count(make_pair(x, y))and mp[{x, y}]) return true;
        bool canPacific = false, canAtlantic = false;
        queue<pair<int,int>> q;
        q.push({x, y});
        hasV[x][y] = true;
        while(not q.empty()){
            auto [curx, cury] = q.front();
            q.pop(); 
            for(int i = 0; i < 4; i++){
                int nx = xx[i] + curx;
                int ny = yy[i] + cury;
                if(nx < 0 or ny < 0) canPacific = true;
                else if(nx > m or ny > n) canAtlantic = true;
                else{
                    if(mp.count(make_pair(nx, ny))){
                        if(mp[{nx, ny}]){
                            mp[{x, y}] = true;
                            return true;
                        }else continue;
                    }
                    if(hasV[nx][ny]) continue;
                    q.push({nx, ny});
                    hasV[nx][ny] = true;
                }
            }
        }
        return mp[{x, y}] = (canAtlantic and canPacific);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        this->heights = heights;
        hasV = vector<vector<bool>>(m, vector<bool>(n, false));
        m = heights.size(), n = heights[0].size();
        vector<vector<int>> ans;
        for(int i = 0; i < m;  i++){
            for(int j = 0; j < n; j++){
                hasV = vector<vector<bool>>(m, vector<bool>(n, false));
                can(i, j);
            }
        }
        for(auto &it : mp){
            if(it.second){
                ans.push_back({it.first.first, it.first.second});
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