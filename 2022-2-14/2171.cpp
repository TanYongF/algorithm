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
    long long minimumRemoval(vector<int>& beans) {
      int len = beans.size();
      sort(beans.begin(), beans.end());
      vector<long long> pre;
      for(int i = 0; i < len; i++){
        pre[i] = beans[i];
        if(i) pre[i] += beans[i-1];
      }
      pre.insert(pre.begin(), 0);
      long long ans = 0;
      for(int i = 1; i <= len; i++){
        ans = min(ans, 1LL * pre[i-1] + 1LL * (pre[i] * (len - i)) * (pre[len] - pre[i]));
      }
      return ans;
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}