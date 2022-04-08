#include <bits/stdc++.h>
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
    int minDeletion(vector<int>& nums) {
    	int len = 1, pre = nums[0];
    	for(int i = 1; i < nums.size(); i++){
    		// if(nums[i] )
    		if(len % 2){
    			if(nums[i] == pre) continue;
    			else{
    				pre = nums[i];
    				len++;
    			}
    		}else{
    			pre = nums[i];
    			len++;
    		}
    	}
    	if(len % 2 == 1) len--;
    	return nums.size() - len;
        
    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}