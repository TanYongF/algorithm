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
    int findSubstringInWraproundString(string p) {
        int len = p.size(), ans = 0;
        int i = 0, j = 0, curLen = 1;
        vector<int> dp(len, 0);
        for(; i < len; i++){
            dp[p[i]-'a'] = max(dp[p[i]-'a'], 1);
            if(i){
                if(p[i] == p[i-1] + 1) curLen++;
                dp[p[i]-'a'] = max(dp[p[i]-'a'], curLen);
            }else curLen = 1;
        }
        ans = accumulate(dp.begin(), dp.end(), 0);
        return ans;
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	string t = "zab";
	cout << s.findSubstringInWraproundString(t);
	/* code */


    return 0;
}