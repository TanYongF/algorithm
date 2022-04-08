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
const int MAXN = 1e6 + 10;
class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
      vector<int> bit(MAXN, 0);
      set<int> st;
      for(auto num : nums) {
        bit[num]++;
        st.insert(num);
      }
      vector<int> ans;
      for(auto num : st){
        if(bit[num] != 1) continue;
        if(num == 0 and bit[1] == 0){
          ans.push_back(0);
          continue;
        }
        if(num == 1000000 and bit[1000000-1] == 0){
          ans.push_back(1000000);
          continue;
        }
        if(num - 1 >= 0 and num + 1 <= (int)1e6 and bit[num-1] == 0 and bit[num+1] == 0) ans.push_back(num);
      }
      return ans;

        
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}