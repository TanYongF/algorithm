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
    bool placeWordInCrossword(vector<vector<char>>& board, string word) {
    	int m = board.size(), n = board[0].size();
    	int len = word.size();
    	int T = 2;
    	while(T--){
    		if(T == 0) reverse(word.begin(), word.end());
			for(int i = 0; i < m; i++){
	    		for(int j = 0; j < n; j++){
	    			int idex = 0;
	    			if(board[i][j] == '#' || (board[i][j] != ' ' && board[i][j] != word[0])) continue;
	    			// cout<< " fa------" << i << " " << j << endl;
	    		
	    			//heng
	    			if((j == 0 || (j > 0 && board[i][j-1] == '#')) && (j + len == n || (j + len < n && board[i][j+len] == '#'))){
	    				for(int k = 0; k < len; k++){
	    					if(board[i][j+k] == '#') break;
	    					else if(board[i][j+k] != ' ' && board[i][j+k] != word[idex]) break;
	    					idex++; 
	    				}

	    				if(idex == len) return true;
	    			}
	    			//shu
	    			idex = 0;
	    			if((i == 0 || (i > 0 && board[i-1][j] == '#')) && (i + len == m || (i + len < m && board[i+len][j] == '#' ))){
	    				cout<< " fa------" << i << " " << j << endl;
	    				for(int k = 0; k < len; k++){
	    					if(board[i + k][j] == '#') break;
	    					else if(board[i + k][j] != ' ' && board[i + k][j] != word[idex]) break;
	    					idex++; 
	    				}
	    				cout << idex;
	    				// cout << idex;
	    				if(idex == len){
	    					return true;
	    				} 
	    			}
	    		}
	    	}
    	}

    	return false; 
    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	vector<vector<char>> board = {{' '},{'#'},{'o'},{' '},{'t'},{'m'},{'o'},{' '},{'#'},{' '}};
	string word = "octmor";
	cout << s.placeWordInCrossword(board,word);
	/* code */


    return 0;
}