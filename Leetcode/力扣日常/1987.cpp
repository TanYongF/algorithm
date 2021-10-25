//https://leetcode-cn.com/contest/weekly-contest-256/problems/number-of-unique-good-subsequences/
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
    int numberOfUniqueGoodSubsequences(string binary) {
    	int len = binary.length(),mod = 1e9+7, last[11];
        long long dp[len+1];
        long long dp2[len+1];
        memset(dp2, 0, sizeof(dp2));
        memset(last, -1, sizeof(last));
        dp[0] = 1;
        // last[s[0]-'a'] = 0;
        for(int i = 1; i <= len; i++){
            int lastIndex = last[binary[i-1]-'0'];
            if(lastIndex == -1) dp[i] = 2*dp[i-1]%mod;
            else dp[i] = (2*dp[i-1]%mod - dp[lastIndex-1])%mod;
            last[binary[i-1]-'0'] = i; 
        }
        dp[len]--;
        // cout << dp[len] << endl;

        memset(last, -1, sizeof(last));
        int k = 0;
        while( k < len &&  binary[k] != '0') k++; 
        if(k >= len) return dp[len] < 0 ? dp[len] + mod : dp[len]; 
   		// cout << k << endl;
   		dp2[k+1] = 1;
        for(int i = k+2; i <= len; i++){
	        int lastIndex = last[binary[i-1]-'0'];
	        if(lastIndex == -1) dp2[i] = 2*dp2[i-1]%mod;
	        else dp2[i] = (2*dp2[i-1]%mod - dp2[lastIndex-1])%mod;
	        last[binary[i-1]-'0'] = i; 
        }
        // cout << dp2[len] << endl;
        long long ans = (dp[len] - dp2[len] + 1)%mod;
        return ans < 0 ? ans + mod : ans;
    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	cout << s.numberOfUniqueGoodSubsequences("001");
	/* code */


    return 0;
}