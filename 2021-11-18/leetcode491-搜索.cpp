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
	int len ;
	vector<int> temp;
	vector<vector<int>> ans;
	vector<int> nums;
    vector<vector<int>> findSubsequences(vector<int>& nums) {
    	this->nums = nums;
    	len = nums.size();
    	dfs(0, INT_MIN);
    	cout << ans.size();
    	return ans;
    }
    void dfs(int curIdx, int last){
    	if(curIdx == len){
    		cout << 1;
    		if(temp.size() >= 2) ans.push_back(temp);
    		return;
    	}
    	if(nums[curIdx] >= last){
    		temp.push_back(nums[curIdx]);
    		dfs(curIdx + 1, nums[curIdx]);
    		temp.pop_back();
    	}
    	if(nums[curIdx] != last){
    		dfs(curIdx + 1, last);
    	}
    }
};

int main(int argc, char * argv[]){

	vector<int> test = {1,2,3,4,5,6,7,8,9,10,1,1,1,1,1};

	Solution s = Solution();
	/* code */
	s.findSubsequences(test);

    return 0;
}