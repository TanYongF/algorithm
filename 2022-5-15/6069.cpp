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
    int largestVariance(string s) {
        int len = s.size(), ans = 0;
        for(char i = 'a'; i <= 'z'; i++){
        	for(char j = 'a'; j <= 'z'; j++){
        		for(int k = 0, dp0 = INT_MIN, dp1 = INT_MIN;  k < len; k++){
        			int v = s[k] == j ? -1 : (s[k] == i ? 1 : 0);
        			if(k == 0){
	        			dp0 = v;
	        			dp1 = v;
        				continue;
        			}
        			dp0 = max(v, dp0 + v);
        			if(s[k] == j) dp1 = max(dp1 + v, max(dp0 + v, v));
        			else dp1 = dp1 + v;
        			ans = max(ans,dp1);
        		}
        	}
        }
        return ans;
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	 


    return 0;
} 	