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
    int countDistinct(vector<int>& nums, int k, int p) {
  		int len = nums.size();
  		int ans = 0, cur = 0;
  		set<vector<int>> st;
  		for(int j = 0, i = 0; j < len; j++){
  			if(nums[j] % p == 0) cur++;
  			while(i < j and cur > k){
  				if(nums[i] % p == 0) cur--;
  				i++;
  			}
  			// ans += (j - i + 1);
  			st.insert(vector<int>(nums.begin()+i, nums.begin() + j + 1));
  		}      
  		return st.size();
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}