//https://leetcode-cn.com/problems/distinct-subsequences/
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
    int numDistinct(string s, string t) {
    	int ss = s.length(), ts = t.length();
    	int dp[ss+1][ts+1];
    	memset(dp, 0, sizeof(dp));
    	for(int i = 0; i <= ss; i++) dp[i][0] = 1;
    	for(int i = 1; i <= ss; i++){
    		for(int j = 1; j <= ts; j++){
    			if(s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
    			else dp[i][j] = dp[i-1][j];
    		}
    	}
    	// cout << "    ";
    	// for(int i = 0; i <= ts; i++) cout  << i << " ";
    	// cout << endl;
    	// for(int i = 0; i <= ss; i++){
    	// 	cout << i << " : " ;
    	// 	for(int j = 0; j <= ts ; j++){
    	// 		cout << dp[i][j] << " ";
    	// 	}
    	// 	cout << endl;
    	// }

    	return dp[ss][ts];

    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	s.numDistinct("rabbbit", "rabit");

	/* code */


    return 0;
}