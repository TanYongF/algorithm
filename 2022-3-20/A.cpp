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
    vector<int> powerHost;
    int divide(int a, int b) {
      if(a == INT_MIN and b == -1) return INT_MAX;
      int limit = INT_MIN >> 1;
      if(a == 0) return 0;
      int sign = (a > 0) ^ (b > 0);
      if(a > 0) a = -a;
      if(b > 0) b = -b;
      int weight = 1;
      while(b > limit){
        b <<= 1;
        weight++;
      }
      int ans = 0;
      while(weight > 0){
        while(a <= b){
          a -= b;
          ans += weight;
        }
        weight--;
        b >>= 1;
      }
      return sign * ans;
    }
};
int main(int argc, char * argv[]){
  int x = -1;
  x <<= 1;
  cout << x << endl;;
  x >>= 1;
  cout << x << endl;

	// Solution s = Solution();
	/* code */


    return 0;

}