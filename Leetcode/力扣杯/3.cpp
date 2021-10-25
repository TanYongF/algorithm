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
	vector<string> t;
	int row ,col;
	int ans =0;
	int dx[8] = {0,  0,  1,  1,  1, -1, -1, -1};
	int dy[8] = {1, -1, -1,  1,  0,  0,  1, -1};
	bool find(int xpos, int ypos){
		// if(xpos < 0 || xpos > row-1 || ypos < 0 || ypos > col-1) return false;
		// if(xpos[i][j] = 'X') return true;
		t[xpos][ypos] = 'X';
		for(int i = 0; i < 8; i++){
			for(int x=xpos+dx[i], y=ypos+dy[i]; x<row && x >= 0 && y < col && y > col && t[x][y]=='O'; x+=dx[i],y+=dy[i])
			if(x>=0 && x<row && y>=0 && y<col && t[x][y]=='X')
				for(int u=xpos+dx[i], v=ypos+dy[i]; u!=x || v!=y; u+=dx[i], v+=dy[i]) if(t[u][v] == 'O') find(u,v);
		}

	}
    int flipChess(vector<string>& chessboard) {
    	row = chessboard.size(), col = chessboard[0].size();
    	int size= 0 , retSize;
    	int ans =0;
    	// memset(hasVisted, false, hasVisted[i]);
		for(int i = 0; i < row; ++i) for(int j = 0; j < col; ++j) if(chessboard[i][j]=='X') size++;
    	for(int i = 0; i < row; ++i) {
    	 	for(int j = 0; j < col; ++j) {
    	 		if(chessboard[i][j] == '.'){
    	 			t = chessboard;
    	 			find(i, j);
    	 			for(int i = 0; i < row; ++i) for(int j = 0; j < col; ++j) if(chessboard[i][j]=='X') retSize++;
    	 			ans = max(ans, retSize-size-1);
    	 		}
    	 		return ans;
    	 	}
    	 } 

    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}