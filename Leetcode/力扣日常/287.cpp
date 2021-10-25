//https://leetcode-cn.com/problems/find-the-duplicate-number/
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
    int findDuplicate(vector<int>& nums) { 
    	for(int i = 0 ; i < nums.size(); i++){
    		while(nums[nums[i]-1] != nums[i]){
    			swap(nums[nums[i]-1], nums[i]);
    		}
    	}
    	for(int i = 0; i < nums.size(); i++)
    		if(nums[i] != i + 1) return i + 1;
   		return nums.size();
    

    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}