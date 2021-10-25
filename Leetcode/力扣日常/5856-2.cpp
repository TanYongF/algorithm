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
    int minSessions(vector<int>& tasks, int sessionTime) {
    	int len = tasks.size(), maxstate = 1 << len;
    	constexpr int INF = 20;
    	vector<int> dp(maxstate, INF);
    	for(int i = 1; i < maxstate; i++){
    		int state = i, spend = 0, index = 0;
    		while(state != 0){
    			if(state&1) spend += tasks[index];
    			index++;
    			state >>= 1;
    		}
    		if(spend <= sessionTime) dp[i] = 1;
    	}
    	for(int i = 1; i < maxstate; i++){
    		if(dp[i] == 1) continue;
    		for(int j = 1; j > 0; j = (j - i) & i){
    			dp[i] = min(dp[i], dp[j]  + dp[i^j]);
    		}
    	}
    	return dp[maxstate-1];
    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}