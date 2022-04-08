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
    vector<int> rearrangeArray(vector<int>& nums) {
      vector<int> a, b;
      for(auto num : nums){
        if(num < 0) b.push_back(num);
        if(num > 0) a.push_back(num);
      }
      vector<int> ans;
      for(int i = 0 ; i < nums.size() /2; i++){
        ans.push_back(a[i]);
        ans.push_back(b[i]);
      }
      return ans;
  }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}