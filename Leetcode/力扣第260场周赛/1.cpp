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
    int maximumDifference(vector<int>& nums) {
    	int ans = -1;
    	for(int i = 0; i < nums.size(); i++){
    		for(int j = i+ 1; j < nums.size(); j++){
    			if(nums[j] > nums[i])
    			ans = max(ans, nums[j] - nums[i]);
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