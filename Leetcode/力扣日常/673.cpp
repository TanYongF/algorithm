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
    int findNumberOfLIS(vector<int>& nums) {
        int len = nums.size();
        int maxx = INT_MIN;
        vector<pair<int,int>> dp(len);
        dp[0] = {1,1};
        for(int i = 1 ; i < len; i++){
            dp[i]= {1,1};
            int m;
            for(int j = i - 1; j >= 0; --j) if(nums[i] > nums[j]) m = max(m, dp[j].first); 
            dp[i]= {m + 1,0};
            for(int j = i - 1; j >= 0; --j){
                if(dp[j].first == m) dp[i].second++;
            }
            maxx = max(maxx, dp[i].first);
        }
        cout << maxx;
        int ans = 0;
        for(int i = 0;  i < len; i++) {
            if(dp[i].first == maxx) ans += dp[i].second;
        }
        return ans;
    }
};

int main(int argc, char * argv[]){

    Solution s = Solution();
    /* code */


    return 0;
}