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
    int reverse(int x) {
      bool flag = x < 0;
      if(not x) return x;
      if(x==INT_MIN) return 0;
      string ux = to_string(x);
      if(flag) ux = ux.substr(1);
      std::reverse(ux.begin(), ux.end());
      while(ux.size()!=11) ux.insert(ux.begin(), '0');
      // unsigned int ans = 0;
      
      string mx = to_string(1<<31), mi = to_string((1<<31)-1);
      auto it = mx.begin();it++;
      mx.insert(it, '0'); mi.insert(mi.begin(), '0');
      // cout << ans;
      if(flag) ux.insert(ux.begin(), '-');
      cout << ux << endl;

      
      if(flag) return ux.compare(mx) == 1 ? 0 : stoi(ux);
      else return ux.compare(mi) == 1 ? 0 : stoi(ux);
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	cout << s.reverse(-2147483647);
	/* code */


    return 0;
}