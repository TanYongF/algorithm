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
    int largestCombination(vector<int>& candidates) {
    	int ans = 0;
    	for(int i = 0; i < 32; i++){
    		int status = 1 << i;
    		int len = 0;
    		for(auto &candidate : candidates){
    			if((candidate & status) != 0) len++;  
    		}
    		ans = max(ans, len);
    	}
    	return ans;
       
    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}