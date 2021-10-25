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

struct TrieNode{
	string s;
	unordered_map<char, TrieNode*> mp;
	TrieNode(){
		this->s = "";
	}
};
void insertTrie(string s, TrieNode *root){
	TrieNode * cur =root;
	for(auto ch : s){
		if(!cur->mp.count(ch))	cur->mp[ch] =  new TrieNode();
		cur = cur->mp[ch];
	}
	cur->s = s;
	// cout <<
}
class Solution {
public:
	int m,n;
	unordered_set<string> st;
	vector<string> res;
	int dx[4] = {0,1,0,-1};
	int dy[4] = {1,0,-1,0};
	void dfs(int x, int y,  TrieNode *root, vector<vector<char>> &board){
		char ch = board[x][y];
		if(!root->mp.count(ch)) return;  
		root = root->mp[ch];
		if(root->s.size() > 0) st.insert(root->s);
		
		board[x][y] = '#';
		for(int i = 0; i < 4; i++){
			int next_x = x + dx[i], next_y = y + dy[i];
			if(next_x >= 0 and next_x < m and next_y >= 0 and next_y < n and board[next_x][next_y] != '#')
				dfs(x + dx[i], y + dy[i], root, board); 
		}
		board[x][y] = ch;
	}
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    	TrieNode *root = new TrieNode();
    	m = board.size(), n = board[0].size();
    	for(auto word : words) insertTrie(word, root); 
    	for(int i = 0; i < m; i++) for(int j = 0; j < n; j++) dfs(i,j,root, board);
    	for(auto str : st) res.emplace_back(str);

    	for(auto re : res)cout<< re;
    	return res;

    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	vector<vector<char>> te = {{'o','a','a','n'},{'e','t','a','e'},{'i','h','k','r'},{'i','f','l','v'}};
	vector<string> ss = {"oath","pea","eat","rain"};
	s.findWords(te, ss);
	/* code */


    return 0;
}