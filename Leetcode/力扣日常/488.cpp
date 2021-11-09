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
const int INF = 6;
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
	unordered_map<string, int> mp;
	int lenHand, lenBorad;
    int findMinStep(string board, string hand) {
    	lenHand = hand.size();
    	lenBorad = board.size();
    	int ret = INF;
    	ret = dfs(board, hand);
    	// cout << ret;
    	return ret == INF ? -1 : ret;
    }
    int dfs(string& board, string &hand){
    	// cout << board << endl;
    	if(board.length() == 0){
    		return 0;
    	} 
    	if(mp.find(board) != mp.end()) return mp[board];
    	int ans = INF;
    	for(int i = 0; i < lenHand; i++){
    		char c = hand[i];
    		if(c == '0') continue;
    		for(int j = 0; j < (int)board.length(); j++){
    			string temp = board.substr(0, j) + c + board.substr(j);
    			simple(temp, j);
    			hand[i] = '0';
    			ans = min(ans, dfs(temp, hand) + 1);
    			hand[i] = c;
    		}
    	}
    	mp[board] = ans;
    	// cout << ans << endl;
    	return ans;
    }
    void simple(string &str,int idx){
    	if(idx < 0) return;
    	int left = idx, right = idx;
    	while(left >= 0 and str[left] == str[idx]) left--;
    	// cout << left << " ";
    	while(right < (int)str.length() and str[right] == str[idx]) right++;
    	int deleteLen = right - left - 1;
    	if(deleteLen >= 3){
    		// cout << left << " " << right << deleteLen << endl;
    		str.erase(left + 1, deleteLen);
    		// cout << str << endl;
    		simple(str, left);
    	}
    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	string board = "WWRRBBWW";
	string hand = "WRBRW";
	cout << s.findMinStep(board, hand);

	// string s2 = "CCBBBBCC";
	// string s1 = "ssaas";
	// s.simple(s1, 4);
	// cout << s1;

	/* code */


    return 0;
}