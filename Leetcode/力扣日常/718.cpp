//https://leetcode-cn.com/problems/maximum-length-of-repeated-subarray/
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
    int findLength(vector<int>& nums1, vector<int>& nums2) {
    	int len1 = nums1.size(), len2 = nums2.size();
    	int dp[len1+1][len2+1];
    	int ans = 0;
    	memset(dp, 0, sizeof(dp));
    	for(int i = 1; i <= len1; i++){
    		for(int j = 1; j <= len2; j++){
    			if(nums1[i-1] == nums2[j-1]){
    				dp[i][j] = dp[i-1][j-1] + 1;
    				ans = max(dp[i][j], ans);
    			}
    				
    		}
    	}
    	return ans;


    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}