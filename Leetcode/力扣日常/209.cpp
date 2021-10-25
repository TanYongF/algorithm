//https://leetcode-cn.com/problems/minimum-size-subarray-sum/
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
	//双指针版本
    int minSubArrayLen(int target, vector<int>& nums) {
    	int len = nums.size(), ans = INT_MAX;
    	nums.insert(nums.begin(), 0);
    	for(int i = 1; i <= len; i++) nums[i] += nums[i-1];
    	int start = 0, end = 0;
    	while(end <= len){
    		while(nums[end] - nums[start] >= target){
    			ans = min(ans, end-start);
    			start++;
    		}
    		end++;

    	}
    	return ans == INT_MAX ? 0 : ans;
    }
    int minSubArrayLen(int target, vector<int>& nums) {
	int len = nums.size(), ans = INT_MAX;
	nums.insert(nums.begin(), 0);
	for(int i = 1; i <= len; i++) nums[i] += nums[i-1];
	int start = 0, end = 0;
	while(end <= len){
		while(nums[end] - nums[start] >= target){
			ans = min(ans, end-start);
			start++;
		}
		end++;

	}
	return ans == INT_MAX ? 0 : ans;
    }


};

int main(int argc, char * argv[]){

	Solution s = Solution();
	vector<int> test = {2,3,1,2,4,3};
	cout << s.minSubArrayLen(7,test);
	/* code */


    return 0;
}