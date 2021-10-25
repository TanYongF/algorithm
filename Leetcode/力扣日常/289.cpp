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
#include <bitset>
#include <list>
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
	int dx[8] = {1,  0,-1, 0,  1, -1, 1, -1};
	int dy[8] = {0 ,-1, 0 ,1 , 1, -1 ,-1 ,1};
    void gameOfLife(vector<vector<int>>& board) {
    	int m = board.size(), n = board[0].size();
    	vector<pair<int,int>> ans;
    	for(int i = 0; i < board.size(); i++){
    		for(int j = 0; j < board[0].size(); j++){
    			int alive = 0;
    			if(board[i][j]){
    				for(int k = 0; k < 8; k++){
    					int next_x = i + dx[k], next_y = j + dy[k];
    					if(next_x > 0 && next_x < m &&  next_y > 0 && next_y < n && board[next_x][next_y]) alive++;  
    				}
    				if(alive == 2 && alive == 3) continue;
    				ans.push_back({i,j});
    			}else{
					for(int k = 0; k < 8; k++){
    					int next_x = i + dx[k], next_y = j + dy[k];
    					if(next_x > 0 && next_x < m &&  next_y > 0 && next_y < n && board[next_x][next_y]) alive++;  
    				}
    				if(alive == 3) ans.push_back({i,j});
    			}
    		}
    	}
    	for(auto it : ans){
    		board[it.first][it.second] = ~ board[it.first][it.second];
    	}

    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}