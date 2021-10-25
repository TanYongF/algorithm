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
	int MOD= 1000000007;
    int securityCheck(vector<int>& capacities, int k) {
    	int len = capacities.size();
    	k++;
    	vector<unordered_map<int,long long>> dp(2);
    	dp[0][k] = 1;
    	for(int i = 1; i <= len ;i++){
    		int curIdx = i & 1, preIdx = (curIdx - 1) & 1;
    		// cout << curIdx << preIdx << endl;
    		dp[curIdx] = dp[preIdx];
    		for(auto &pre : dp[preIdx]) {
    			int cur = pre.first - capacities[i-1] + 1;
    			if(cur > 0) dp[curIdx][cur] = (dp[curIdx][cur] + pre.second) % MOD;
    		}
    		dp[preIdx] = dp[curIdx];
    	}
    	return dp[len & 1][1];
    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	vector<int> capacities = {2,2,3};
	cout << s.securityCheck(capacities, 2);

	/* code */


    return 0;
}