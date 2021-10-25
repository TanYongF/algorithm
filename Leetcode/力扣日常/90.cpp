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
    vector<vector<int>> ans;
    vector<int> t;
    void dfs(int index, vector<int> &nums, bool chooseBefore){
        if(index == nums.size()) ans.push_back(t);
        if(index >= 1 && nums[index] == nums[index-1] && !chooseBefore) return;
        //No
        dfs(index+1, nums, false);
        //Yes
        t.push_back(nums[index]);
        dfs(index+1, nums, true);
        t.pop_back();
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        dfs(0, nums, false);
        return ans;
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}