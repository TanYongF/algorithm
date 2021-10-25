//https://leetcode-cn.com/problems/distinct-subsequences-ii/
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
    int distinctSubseqII(string s) {
    	int len = s.length(),mod = 1e9+7, last[26];
        long long dp[len+1];
        memset(last, -1, sizeof(last));
        dp[0] = 1;
        // last[s[0]-'a'] = 0;
        for(int i = 1; i <= len; i++){
            int lastIndex = last[s[i-1]-'a'];
            if(lastIndex == -1) dp[i] = 2*dp[i-1]%mod;
            else dp[i] = 2*dp[i-1]%mod - dp[lastIndex-1];
            last[s[i-1]-'a'] = i;
            
        }
        dp[len]--;
    	return dp[len]<0 ? dp[len]+mod : dp[len];
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	cout << s.distinctSubseqII("a");


    return 0;
}