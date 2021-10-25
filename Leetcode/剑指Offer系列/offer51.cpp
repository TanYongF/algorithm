//https://leetcode-cn.com/problems/shu-zu-zhong-de-ni-xu-dui-lcof/
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
	int c[100000];
	int MAX = INT_MIN;
	int lowbit(int x) {return x & (-x);}
	void add(int x, int k){
		while(x <= MAX){
			c[x] = c[x] + k;
			x += lowbit(x);
		}
	}
	int getsum(int x){
		int ans = 0;
		while(x >= 1){
			ans += c[x];
			x = x - lowbit(x);
		}
		return ans;
	}
    int reversePairs(vector<int>& nums) {
    	int ret= 0 ;
    	vector<int> temp = nums;
    	sort(temp.begin(), temp.end());
    	for(auto &num : nums) num = lower_bound(temp.begin(), temp.end(), num)- temp.begin() + 1;
    	for(auto num : nums)  MAX = max(MAX, num);
    	for(int i = 0; i < nums.size(); i++){
    		int cur = nums[i];
    		ret += (getsum(MAX) - getsum(cur+1));
    		add(cur, 1);
    	}
    	return ret;
    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}