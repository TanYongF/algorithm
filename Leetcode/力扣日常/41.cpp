//https://leetcode-cn.com/problems/first-missing-positive/
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
#include <bitset>
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

//bitset
// const int MAXN = 500010;
// class Solution {
// public:
//     int firstMissingPositive(vector<int>& nums) {
//     	int len = nums.size();
//     	bitset<MAXN> bt;
//     	for(auto num : nums){
//     		if(num < 0 || num > len) continue;
//     		bt |= 1 << num;
//     	}
//     	for(int i = 1; i <= len; i++){
//     		if(bt[i] == 0) return i;
//     	}
//     	return len;
//     }
// };

//原地Hash
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
    	int len = nums.size();
    	for(int i = 0; i < len; i++){
    		if(nums[i] > 0 && nums[i] <= len && nums[nums[i]-1] != nums[i]){
    			swap(nums[nums[i]-1], nums[i]);
    		}
    	}
    	for(int i = 0; i < len; i++){
    		if(nums[i] != i + 1) return i+1;
    	}
    	return len+1;
    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}