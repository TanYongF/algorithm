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
    int countKDifference(vector<int>& nums, int k) {
    	int ans = 0;
    	int len = nums.size();
    	for(int i = 0; i < len; i++){
    		for(int j = i+1; j < len; j++){
    			if(abs(nums[i] - nums[j]) == k) ans++;
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