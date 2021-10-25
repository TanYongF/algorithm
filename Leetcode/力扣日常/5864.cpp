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
    int findMiddleIndex(vector<int>& nums) {
    	int len = nums.size();
    	int sum = 0 , cur = 0;
    	if(sum % 2 != 0) return -1;
    	for(auto num : nums) sum += num;
    	for(int i = 0; i < len; i++){
    		if(cur == sum - cur - nums[i]) return i;
    		cur += sum;
    	}
    	return -1;

    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}