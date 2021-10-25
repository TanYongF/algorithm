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
    int sumOfBeauties(vector<int>& nums) {
    	int len = nums.size();
    	int maxx[len], minn[len];
    	maxx[0] = nums[0];
    	minn[len-1] = nums[len-1];
    	for(int i = 1; i < len; i++) {
    		maxx[i] = max(maxx[i-1], nums[i]);
    	}
    	for(int i = len-2; i >= 0; i--){
    		minn[i] = min(minn[i+1], nums[i]);
    	}
    	int ans = 0;
    	for(int i = 1; i < len-1; i++){
    		if(nums[i] > maxx[i-1] && nums[i] < minn[i-1]) ans += 2;
    		else if(nums[i] > nums[i-1] && nums[i] < nums[i+1]) ans += 1;
    	}
    	return ans;
    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}