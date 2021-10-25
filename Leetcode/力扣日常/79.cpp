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
	int xx[4] = {0,1,0,-1};
	int yy[4] = {1,0,-1,0};
	int m, n, len;
	bool ret = false;
	string word;
	vector<vector<char>> board;
	vector<vector<bool>> hasVisted;
    bool exist(vector<vector<char>>& board, string word) {
    	int m = board.size(), n = board[0].size();
        this->hasVisted = vector<vector<bool>>(m, vector<bool>(n, false));
    	this->word = word, this->board = board;
    	for(int i = 0; i < m and not ret; ++i)
    		for(int j = 0; j < n and not ret; ++j)
    			if(word[0] == board[i][j]) backTacing(1, i, j);
    	return ret;
    }
    void backTacing(int curIdx, int curX, int curY){
    	if(curIdx == len){
    		ret = true;
    		return;
    	}
    	for(int i = 0; i < 4 and not ret; i++){
    		int nextX = xx[i] + curX, nextY = yy[i] + curY;
    		if(nextX >= 0 and nextX < m and nextY >= 0 and nextY < n and not hasVisted[nextX][nextY] and word[curIdx] == board[nextX][nextY]){
    			hasVisted[nextX][nextY] = true;
    			backTacing(curIdx + 1, nextX, nextY);
    			hasVisted[nextX][nextY] = false;
    		}
    	}
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	


    return 0;
}