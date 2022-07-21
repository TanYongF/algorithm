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
    int maximumXOR(vector<int>& nums) {
    	vector<int> bits(32,0);
    	for(auto num : nums){
    		int i = 0;
    		while(num){
    			bits[i++] += (num & 1);
    			num >>= 1;
    		}
    	}
    	long long ans = 0;
    	for(int i = 0; i < 32; i++){
    		if(bits[i] >= 1) ans += (1 << i);
    	}
    	return ans;
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}