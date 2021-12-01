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

int mv[1002][1002];
int m, n;
class Solution {
public:
	// unordered_map<int,int> mp;
    int countPyramids(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
       
        if(m == 1 || n < 3) return 0;
        vector<vector<int>> inv(m);
        int idx = 0;
        for(int i = m-1; i >= 0; i--){
        	for(int j = n-1; j >=0; j--){
        		inv[idx].push_back(grid[i][j]);
        	}
        	
        }
        return slove(grid) + slove(inv);

    }
    int slove(vector<vector<int>>& grid){ 
     	memset(mv, 0, m * n);
	    for(int i = 0; i < m; i++){
	    	for(int j = n-1; j >= 0; j--){
	    		if(grid[i][j] == 0) mv[i][j] = -1;
	    		else{
	    			if(j == n-1) mv[i][j] = j;
	    			else{
	                    mv[i][j] = mv[i][j+1] > 0 ? mv[i][j+1] : j;
	                } 
	    		}
	    	}
	    }
	    // for(int i = 0; i < m; i++){
	    //     for(int j = 0; j < n; j++) cout << mv[i][j] << " ";
	    //     cout << endl;
	    // }

	    int ans =0;
	    for(int i = 0; i < m; i++){
	    	for(int j = 0; j < n; j++){
	    		ans += get(i, j, grid);
	    	}
	    }
	    return ans;

    }
    int get(int x, int y,vector<vector<int>>& grid){
    	int dep = 1;
    	if(grid[x][y] == 0) return 0;
    	else{
    		for(int i = x + 1; i < m; i++){
    			int ss = y - (i - x), se = y + (i - x);
                cout << ss << " " <<se << endl;
    			if(ss < 0) break;
    			else if(se > mv[i][ss]) break;
    			else dep++; 
    		}
    	}
        cout << x << " " << y << " "<< dep << endl;
    	return dep - 1;
    }
};


int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}