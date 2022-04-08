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
    vector<long long> maximumEvenSplit(long long finalSum) {
      vector<long long> ans;
      if(finalSum % 2 != 0) return ans;
      long long cur = 2;
      while(finalSum >= cur){
        ans.push_back(cur);
        finalSum -= cur;
        cur +=2;
      }
      if(finalSum) *ans.rbegin() += finalSum;
      return ans;       
    }
};
int main(int argc, char * argv[]){

  Solution s = Solution();
  s.maximumEvenSplit(20000);
  /* code */


    return 0;
}