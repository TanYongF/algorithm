#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <string>
#include <cstring>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <ctime>
#include <climits>
#include <vector>
#include <iostream>
#include <fstream>
#include <list>
#include <iomanip>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;



class Solution {
public:
	// int f[310];
 //    // int sg(int x, int maxChoosableInteger){
 //    // 	if(f[x] != -1) return f[x];
 //    // 	unordered_set<int> st;
 //    // 	for(int i = 1; i <= maxChoosableInteger; i++)
 //    // 		if(x >= i) st.insert(sg(x-i, maxChoosableInteger));
 //    // 	for(int i = 0; ; i++){
 //    // 		if(!st.count(i)){
 //    // 			f[x] = i;
 //    // 			break;
 //    // 		}
 //    // 	}
 //    // 	return f[x];
 //    // }
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
    	if(maxChoosableInteger >= desiredTotal) return true;
    	if((1+maxChoosableInteger)*maxChoosableInteger/2 < desiredTotal) return false;
    	vector<int> dp(pow(2, maxChoosableInteger)+1, -1);
    	return (bool)dfs(0, dp, maxChoosableInteger, desiredTotal);
    }
    bool dfs(int state, vector<int>& dp, int maxChoosableInteger, int desiredTotal){
    	if(dp[state] != -1) return dp[state];
    	for(int i = 1; i <= maxChoosableInteger; i++){
    		int cur = 1 << (i-1);
    		if((cur&state)!=0) continue;
    		if(i >= desiredTotal || !dfs((state|cur), dp, maxChoosableInteger, desiredTotal-i))
    			return (dp[state]=1);
    	}
    	return (dp[state] = 0);
    }

    
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	cout << s.canIWin(10, 9);
	/* code */


    return 0;
}