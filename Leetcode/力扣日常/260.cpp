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
    vector<int> singleNumber(vector<int>& nums) {
    	int sum = 0;
    	for(auto num : nums) sum ^= num;
    	int lowbit = (sum == INT_MIN ? sum : sum & (-sum));
    	int type1= 0 , type2 =0;
    	for(auto num : nums){
    		if(num & lowbit){
    			type1 ^= num;
    		}else{
    			type2  ^= num;
    		}
    	}

    	return {type1, type2};



    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	int num = INT_MIN;
	while(num != 0){
		cout << (num & 1);
		num >>= 1;
	}
	/* code */


    return 0;
}