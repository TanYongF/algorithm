//https://leetcode-cn.com/problems/surrounded-regions/
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
	bool flag;
	vector<vector<bool>> hasVisted;
	vector<pair<int,int>> temp;
	vector<vector<char>> board;
	int x[4] = {0,1,0,-1};
	int y[4] = {1,0,-1,0};
	bool check(int i , int j){
		return  i != 0 && i != board.size()-1 && j != 0 && j != board[0].size()-1;
	}
	void dfs(vector<vector<char>>& board, int i, int j){
		if(i < 0 || i > board.size()-1 || j < 0 || j > board[0].size()-1 || board[i][j] != 'O' || hasVisted[i][j]) return;
		if(!check(i,j)) flag = false;
		hasVisted[i][j] = true;
		temp.push_back({i,j});
		for(int k = 0; k < 4; k++) dfs(board, i + x[k], j + y[k]);
	}
    void solve(vector<vector<char>>& board) {
    	this->board = board;
    	int m = board.size(),  n= board[0].size();
    	hasVisted = vector<vector<bool>>(m, vector<bool>(n,false));
    	for(int i = 0 ;i < m; i++){
    		for(int j = 0; j < n; j++){
    			if(!hasVisted[i][j] && board[i][j] == 'O'){
    				// cout <<  i << j << endl;
    				temp.clear();
    				flag = true;
    				dfs(board, i, j);
    				if(flag) for(auto t : temp) board[t.first][t.second] = 'X'; 
    			}
    		}
    	}
    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	vector<vector<char>> temp ={{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}};
	s.solve(temp);
	for(auto a : temp){
		for(auto it : a){
			cout << it << " ";
		}
		cout << endl;
	}
	/* code */


    return 0;
}