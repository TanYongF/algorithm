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
	unordered_map<int,int> mp;
	int maxChoosableInteger;
	bool dfs(int status){
		if(mp.count(status)) return mp[status];
		bool cur = true;
		for(int i = 0; i < maxChoosableInteger; i++){
			if((status & (1 << i))) continue;
			cur &= dfs(status | (1 << i)); 
		}
		if(cur) mp[status] = false;
		else mp[status] = true;
		return mp[status];
	}
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
    	this->maxChoosableInteger = maxChoosableInteger;
    	for(int i = 0; i < (1 << maxChoosableInteger) - 1; i++){
    		int sum = 0;
    		for(int j = 0; j < maxChoosableInteger; j++) if((i >> j)&1) sum += (j+1);
    		if(sum >= desiredTotal){
    			mp[i] = false;
    			// cout << i << " " << mp[i] << endl; 
    		} 
    	}
    	return dfs(0);
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	cout << s.canIWin(10, 11);
	/* code */


    return 0;
}