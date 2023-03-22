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
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 查找"iflytek"子串
     * @param str string字符串 输入字符串
     * @return int整型
     */
	int find(string s, string t){
		int m = s.size(), n = t.size();
		int dp[m + 1][n+1];
		for(int i = 0; i <= n; i++) dp[0][i] = 0;
		for(int i = 0; i <= m; i++) dp[i][0] = 1;
		for(int i = 0; i <= m; i++){
			for(int j = 0; j <= n; j++){
				if(s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
				else dp[i][j] = dp[i-1][j];
			}
		}
		return dp[m][n];
	}
    int findIflytek(string str) {
    	string t = "iflytek";
    	return find(str, t);
        // write code here
        
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}