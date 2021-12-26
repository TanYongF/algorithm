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
	int x[4] = {0, -1, 0, 1};
	int y[4] = {1, 0, -1, 0};
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
    	int start = 0;
    	int len = s.size();
    	vector<int> ans;
    	for(; start < len-1; start++){
    		int t = 0;
    		int x = startPos[0], y = startPos[1];
    		for(int i =  start; i < len; i++){
    			if(s[i] == 'L'){
    				y--;
    			}else if(s[i] == 'R'){
    				y++;
    			}else if(s[i] == 'U'){
    				x--;
    			}else if(s[i] == 'D'){
    				x++;
    			}
    			if(y < 0 or y >= n or x < 0 or x >= n) break;
    			t++;
    		}
    		ans.push_back(t);
    	}
    	return ans;
        
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}