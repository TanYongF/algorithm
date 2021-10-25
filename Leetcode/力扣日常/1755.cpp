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
	set<ll> left;
	set<ll> right;
	vector<ll> un;
    int minAbsDifference(vector<int>& nums, int goal) {
    	int len = nums.size();
    	int harf = len / 2;
    	get(0,     0,  harf, nums);
    	get(harf+1,0, len-1, nums);
    	ll ans = INT_MAX;
    	for(auto &it : left) {ans = min(abs(it - goal), ans);}
    	for(auto &it : right) ans = min(abs(it - goal), ans); 
    	if(ans == 0) return 0;
    	auto left_it = left.begin();
    	auto right_it  = right.rbegin();
    	while(left_it != left_it.end() and right_it != right_it.rend()){
    		ans = min(abs(*left_it + *right_it - goal), ans);
    		if(*left_it + *right_it == goal) return 0;
    		else if(*left_it + *right_it < goal) left_it++;
    		else right_it++;
    	}
    	return ans;
    	

    }
    void get(int curIdx,int curNum, int end, vector<int> &nums){
    	if(curIdx == end + 1){
    		left.insert(curNum);
    		return;
    	}
    	get(curIdx + 1, curNum, end, nums);
    	get(curIdx + 1, curNum + nums[curIdx], end,nums);
    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}