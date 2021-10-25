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
    int countQuadruplets(vector<int>& nums) {
    	
    	int len = nums.size(), ans = 0;
    	for(int i = 0; i <  len-3; i++){
    		for(int j = i + 1; j < len-2; j++){
    			for(int k = j+1; k < len-1; k++){
    				for(int m = k+1; m < len; m++){
    					if(nums[i]+nums[j]+nums[k] == nums[m]) ans++;
    				}
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