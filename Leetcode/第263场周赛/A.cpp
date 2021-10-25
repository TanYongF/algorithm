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
    bool areNumbersAscending(string s) {
    	int len = s.length();
    	vector<int> nums ;
    	int j;
    	for(int i = 0; i < len; i = j){
    		j = i;
    		int cur = 0;
    		while(j < len and s[j] >= '0' and s[j] <= '9'){
    			cur = (10 * cur) + (s[j] - '0');
    			j++;
    		}
    		nums.push_back(cur);
    	}
    	for(int i = 1; i < nums.size(); i++){
    		if(nums[i] <=  nums[i-1]) return false;
    	}
    	return true;
        
    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}