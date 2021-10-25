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
    int maxProduct(vector<int>& nums) {
    	int len = nums.size();
    	nums.insert(nums.begin(), 0);
    	long long dp[len+1][2], ans = INT_MIN;
    	memset(dp, 0, sizeof(dp));
    	dp[0][0] = dp[0][1] = 0;
    	for(int i = 1; i <= len; i++){
    		if(nums[i] < 0){
    			dp[i][1] = min((long long)nums[i] , dp[i-1][0] * nums[i]);
    			dp[i][0] = dp[i-1][1] * nums[i];
    		}else if(nums[i] > 0){
    			dp[i][0] = max((long long)nums[i], dp[i-1][0] * nums[i]);
    			dp[i][1] = dp[i-1][1] * nums[i];
    		}
    		ans = max(ans , dp[i][0]);
    	}
    	return ans;
    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}