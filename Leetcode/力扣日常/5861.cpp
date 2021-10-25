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
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        int dp[n];
        memset(dp, 0, sizeof(dp));
        map<int ,vector<pair<int,int>> > mp;
        for(auto ride : rides){
        	mp[ride[1]].push_back({ride[0], ride[1] - ride[0] + ride[2]});
        }
        for(int i = 1 ; i <= n; i++){
        	dp[i] = dp[i-1];
        	for(auto &it : mp[i]){
        		dp[i] = max(dp[i], dp[it.first] + it.second);
        	}
        }
        return dp[n];
      
    }
};

int main(int argc, char * argv[]){
Solution s = Solution();
	vector<vector<int>> a = {{1,6,1},{3,10,2},{10,12,3},{11,12,2},{12,15,2},{13,18,1}};
	s.maxTaxiEarnings(200000, a);
	
	/* code */


    return 0;
}