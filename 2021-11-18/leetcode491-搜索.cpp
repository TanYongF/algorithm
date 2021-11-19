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


/*减枝策略： 如果有两个是一样的：
1. 前者不选择，后者不选择。
2. 前者选择， 后者选择
3. 前者不选择， 后者选择
4. 前者选择，后者不选择
其中3，4两种策略是一样的，我们使用1，2，4策略。
*/
class Solution {
public:
	__int128 tst = 10;;
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
    	//前者选择或不选择 ==> 后者选择
    	if(nums[curIdx] >= last){
    		temp.push_back(nums[curIdx]);
    		dfs(curIdx + 1, nums[curIdx]);
    		temp.pop_back();
    	}
    	//前者不选择 ==> 后者不选择
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