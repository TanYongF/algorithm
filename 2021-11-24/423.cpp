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
    string originalDigits(string s) {
		vector<int> cnt(27,0);
		vector<int> ans(11,0);
    	for(auto ch : s) cnt[(ch - 'a')]++;
    	ans[0] = cnt['z'-'a'];
    	ans[2] = cnt['w'-'a'];
    	ans[4] = cnt['u'-'a'];
    	ans[6] = cnt['x'-'a'];
    	ans[8] = cnt['g'-'a'];
    	ans[5] = cnt['f'-'a']-ans[4];
    	ans[7] = cnt['v'-'a']-ans[5];
    	ans[9] = cnt['i'-'a']-ans[8]-ans[6]-ans[5];
    	ans[1] = cnt['o'-'a']-ans[0]-ans[4]-ans[2];
    	ans[3] = cnt['r'-'a']-ans[0]-ans[4];
    	string ret;
    	for(int i = 0; i <= 10; i++){
    		ret += string(ans[i], i + 48);
    	}
    	return ret;
    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	string str = "459";
	cout << s.originalDigits(str);
	/* code */


    return 0;
}