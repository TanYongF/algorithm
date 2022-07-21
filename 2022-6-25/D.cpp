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
int gcd(int x, int y){
    return y ? gcd(y, x % y) : x;
}
class Solution {
public:
	int mod = 1e9 + 7;
    int distinctSequences(int n) {
    	long long dp[n][7];
    	memset(dp, 0, sizeof(dp));
    	for(int j = 1; j <= 6; j++) dp[0][j] = 1;
    	for(int i = 1; i < n; i++){
    		for(int j = 1; j <= 6; j++){
				int del = 0;
				if(i >= 2){
					int num = dp[i-2][j];
					unordered_set<int> st;
					for(int m = 1; m <= 6; m++) if(gcd(m, j) == 1) st.insert(m);
					for(int n = 1; n <= 6; n++){
						for(auto it : st){
							if(gcd(it, n) == 1) del += num;
						}
					} 

				}
    			for(int k = 1; k <= 6; k++){
    				if(gcd(j, k) == 1) continue;		
    				dp[i][j] = (dp[i][j] + dp[i-1][k]) % mod;
    			}
				dp[i][j] = (dp[i][j] - del) % mod;
				if(dp[i][j] < 0) dp[i][j] += mod;
    		}
    	}
    	long long ans = 0;
    	for(int i = 1; i <= 6; i++){
    		ans = (ans + dp[n-1][6]) % mod;
    	}
    	return ans; 
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}