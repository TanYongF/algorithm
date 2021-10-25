//https://leetcode-cn.com/problems/regular-expression-matching/
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
	bool match(char s, char p){
		if(p == '.' || p == s) return true;
		return false;
	}
    bool isMatch(string s, string p) {
        int s_len = s.length() ,p_len = p.length();
        bool dp[p_len+1][s_len+1];
        bool many[p_len+1];
        memset(many, false, sizeof(many));
        int size = 0;
        int idx = 0;
        for(int i = 0; i < p_len; i++){
        	if(p[i] == '*'){
        		many[idx-1] = true;
        	}else{
        		p[idx++] = p[i];
        	}
        }
        p_len = idx;
        // for(int i = 0; i < idx; i++) cout << p[i] << " ";
        // 	cout << endl;
        // for(int i = 0; i < idx; i++) cout << many[i] << " ";	
        // 	cout << endl;
        memset(dp, false, sizeof(dp));
        dp[0][0] = true;
        char cur;
        for(int i = 1; i <= p_len; i++){
        	bool flag = true;
            for(int j = 0; j <= s_len && flag; j++){
            	if(many[i-1]){
            		dp[i][j] = dp[i-1][j];
            		if(j > 0 && match(s[j-1],p[i-1])) dp[i][j] |= (dp[i-1][j-1] || dp[i][j-1]);
            	}else{
            		if(j > 0){
            			dp[i][j] = match(s[j-1],p[i-1]) && dp[i-1][j-1];
            		}
            	}

            }
        }
         //  for(int i = 1; i <= p_len; i++){
         //    for(int j = 0; j <= s_len; j++){
         //    	cout << dp[i][j] << " ";
         //    }
         //    	cout << endl;
        	// }
        return dp[p_len][s_len];
    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	cout << s.isMatch("aab",
"c*a*b");
	/* code */


    return 0;
}