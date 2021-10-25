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
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
    	vector<int> dp(amount+1, INT_MAX);
    	dp[0] = 0;
    	for(auto coin : coins){
    		for(int i = 1; i <= amount; i++){
    			if(i >= coin) dp[i] = min(dp[i], dp[i-coin]+1); 
    		}
    	}
    	return dp[amount];
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}