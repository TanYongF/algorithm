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
    int numDecodings(string s) {
    	int len = s.length(), MOD = 1e9 + 7;;
    	long long dp[len+1];
    	dp[0] = 1;
    	if(s[0] == '0') return 0;
    	dp[1] = s[0] == '*' ? 9 : 1;
    	for(int i = 2; i <= len; i++){
    		if(s[i-1] == '0'){
    			if(s[i-2] > '2' || s[i-2] == '0') return 0;
    			if(s[i-2] == '*' || s[i-1] == '2') dp[i] = 2 * dp[i-2] % MOD;
    			else  dp[i] = dp[i-2]; 
    			continue;
    		}
    		if(s[i-1] != '*' && s[i-2] != '*'){
    			dp[i] = dp[i-1];
    			if(s[i-2] == '1' || (s[i-2] == '2' && s[i-1] <= '6')) dp[i] = (dp[i] + dp[i-2]) % MOD; 
    		}else if(s[i-1] != '*' && s[i-2] == '*'){
    			dp[i] = dp[i-1];
    			if(s[i-1] <= '6') dp[i] =( dp[i-1] + 2*dp[i-2]%MOD) % MOD;
    			else dp[i] = (dp[i-1]+dp[i-2])%MOD;
    		}else if(s[i-1] == '*' && s[i-2] == '*'){
    			dp[i] = ((9*dp[i-1])%MOD + (15*dp[i-2]))%MOD;
    		}else{
    			dp[i] = 9*dp[i-1]%MOD;
    			if(s[i-2] == '1') dp[i] = (dp[i] + (9*dp[i-2]%MOD)) %MOD; 
    			else if(s[i-2] == '2') dp[i] = (dp[i] + (6*dp[i-2]%MOD)) %MOD;
    		}
    	}
    	for(int i = 1 ; i<= len; i++) cout << dp[i] << " " ;
    		cout << endl;
    	return dp[len];
    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	string s1 = "1003";
	cout<< s.numDecodings(s1);
	/* code */


    return 0;
}