//https://leetcode-cn.com/problems/first-day-where-you-have-been-in-all-the-rooms/
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
    int firstDayBeenInAllRooms(vector<int>& nextVisit) {
        int mod = 1e9+7;
        int len = nextVisit.size();
        nextVisit.insert(nextVisit.begin(), -1);
        for(int i = 0; i < len; i++) nextVisit[i]++;
        long long dp[100010];
       	memset(dp, 0, sizeof(dp));
       	dp[1] = 2;
       	for(int i = 2; i <= len-1; i++){
       		dp[i] = (1 +  dp[i-1] - dp[nextVisit[i]-1] + 1) % mod;
       		dp[i] = (dp[i] + dp[i-1])%mod;
       	}
       	return dp[len-1];

    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	vector<int> v = {0,1,2,0,1};
	cout << s.firstDayBeenInAllRooms(v);
	/* code */


    return 0;
}