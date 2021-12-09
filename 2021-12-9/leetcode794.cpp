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
	int xn = 0, on = 0;
	bool flag = true;
	char ch ;
	bool xok = false, ook = false;
    bool validTicTacToe(vector<string>& board) {
    	for(int i = 0; i < 3; i++){
    		for(int j = 0; j < 3; j++){
    			if(board[i][j] == 'X') xn++;
    			else if(board[i][j] == 'O') on++;
    		}
    	}
    	for(int i = 0; i < 3; i++){
    		ch = board[i][i];
    		if(board[i][0] == ch and board[i][1] == ch and board[i][2] == ch) ch == 'X' ? xok = true : ook = true;
    		if(board[0][i] == ch and board[1][i] == ch and board[2][i] == ch) ch == 'X' ? xok = true : ook = true;
    	}
    	ch = board[1][1];
    	if(board[2][0] == ch and board[0][2] == ch) ch == 'X' ? xok = true : ook = true;
		if(board[0][0] == ch and board[2][2] == ch) ch == 'X' ? xok = true : ook = true;   		
        if(ook or xok){
            if(xn == on) return not xok;
            else if(xn - on == 1) return not ook;
        }
        return xn >= on and xn - on <= 1;
	}
};



int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}