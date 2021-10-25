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
    bool ans = false;
    int m,n;
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        for(int i = 0; i < m && !ans ; i++){
            for(int j = 0; j < n && !ans; j++){
                bfs(word, 0, i, j, board);
            }
        }
        return ans;
    }
    void bfs(string& word, int idx, int x, int y,vector<vector<char>>& board){
        if(idx == word.length()) {
            ans = true;
            return;
        }
        if(x < 0 || x > m-1 || y < 0 || y < n-1 || board[x][y] == '.' || board[x][y] != word[idx]) return;
        char cur  = board[x][y];
        board[x][y] =  '.';
        for(int i = 0; i < 4 && !ans; i++){
            bfs(word, idx+1, x +  dx[i], y + dy[i],  board);
        }
        board[x][y] = cur;
    }
};
int main(int argc, char * argv[]){

    Solution s = Solution();
    /* code */


    return 0;
}