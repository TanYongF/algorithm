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
    int removeDuplicates(vector<int>& nums) {
    	int i = 1, j = 1, k = 1;
    	for(; j < nums.size(); j++){
    		if(nums[j] == nums[j-1]) k++;
    		else k = 1;
    		if(k > 2) continue;
    		nums[i++] = nums[j];
    	}
    	return i;

    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	vector<int> t = {1,3,3,3,4};
	cout <<s.removeDuplicates(t);
	for(auto it :t) cout << it << " ";
	/* code */


    return 0;
}