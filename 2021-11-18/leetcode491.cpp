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
    vector<vector<int>> findSubsequences(vector<int>& nums) {
    	int ans = 0, len = nums.size();
    	vector<unordered_set<bitset<15>>> dp(len);
    	set<vector<int>> st;
    	for(int i = 1; i < len; i++){
    		int j = 0;
    		if(nums[i] == nums[i-1]) j = i - 1;
    		for(; j < i; j++){
    			if(nums[i] >= nums[j]){
    				bitset<15> temp;
    				temp[i] = 1, temp[j] = 1;
    				dp[i].insert(temp);
    				for(auto it : dp[j]){
    					it[i] = 1;
    					dp[i].insert(it);
    				}
    			}
    		}
    	}
    	int s1 = 0, s2 = 0;
    	// vector<vector<int>> ret(st.begin(), st.end());
    	for(auto d : dp){
    		for(auto it : d){
    			vector<int> temp;
    			for(int i = 0; i < len; i++) if(it[i]) temp.push_back(nums[i]);
    			st.insert(temp); 
    			// cout << 1;
    		}
    	}
    	vector<vector<int>> ret(st.begin(), st.end());
    	// s2 = st.size();
    	// cout << s1 << " " << s2;
    	// return 0;
    	return ret;
    }
    // void backtrace(){

    // }
};

int main(int argc, char * argv[]){
	vector<int> test = {1,2,3,4,5,6,7,8,9,10,1,1,1,1,1};

	Solution s = Solution();
	/* code */
	s.findSubsequences(test);

    return 0;
}