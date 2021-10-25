#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <string>
#include <cstring>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <ctime>
#include <unordered_map>
#include <climits>
#include <vector>
#include <iostream>
#include <fstream>
#include <list>
#include <iomanip>
#include <numeric>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> item;
    int length;
    unordered_map<int,bool> mp[4];
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        length = nums.size();
        sort(nums.begin() , nums.end());
        nums.insert(nums.begin(), INT_MIN);
        backTracing(0, 0, target,1,nums);
        return res;
    }
    void backTracing(int cursize, int curSum, int target, int index,vector<int> &nums){
        if(curSum > target) return ;
        if(cursize == 4 && curSum == target){
            vector<int> resItem = vector<int>(item);
            res.push_back(resItem);
            return;
        }else if(cursize == 4) return;
        for(unsigned i = index; i <= length; ++i) {
        	if(mp[cursize][nums[i]] && nums[i] == nums[i-1]) continue;
            item.push_back(nums[i]);
            mp[cursize][nums[i]] = true;
            backTracing(cursize+1, curSum + nums[i] , target, i+1,nums);
        	item.pop_back();
        	mp[cursize][nums[i]] = false;
        }
        return;
    }
};

int main(int argc, char * argv[]){
	Solution s = Solution();
	vector<int> t;
	t.push_back(1);
	t.push_back(0);
	t.push_back(-1);
	t.push_back(0);
	t.push_back(-2);
	t.push_back(2);
	s.fourSum(t,0);
	cout << s.res.size();
	for(auto nums: s.res){
		for(auto num  : nums){
			cout << num << " " ;
		}
	}

	/* code */


    return 0;
}