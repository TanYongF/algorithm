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
#include <bitset>
#include <list>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
	vector<int> nums;
	long long maxnn;
	int len, ans = 0;

    int countMaxOrSubsets(vector<int>& nums) {
    	
    	for(auto num : nums) maxnn |= num;
    	len = nums.size();
    	int bit = pow(2, len);
    	// cout << 
    	this->nums = nums;
    	for(int i = 0; i < bit; i++){
    		int cur = 0;
    		for(int j = 0; j < len; j++){
    			if( (i >> j) & 1) cur |= nums[j];
    		}
    		if(cur == maxnn) ans++;
    	}
    	return ans;
        
    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	vector<int> test = {3,1};
	cout << s.countMaxOrSubsets(test);
	/* code */


    return 0;
}