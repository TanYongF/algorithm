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
    int maximumGood(vector<vector<int>>& statements) {
      int n = statements.size();
      int ans = 1;
      if(n == 1) return 1;
      for(int i = 0; i <= (1 >> (n - 1)); i++){
        int cur = i;
        vector<bool> is(n, false);
        int j = 0, num =0;
        while(cur){
          is[j] = cur & 1;
          if(is[j] == true) num++;
          cur = cur >> 1;
          j++;
        }
        bool flag = true;
        for(int m = 0; m < n and flag; m++){
          if(not is[m]) continue;
          for(int k = 0; k < n; k++){
              if((statements[m][k] == 0 and not is[k]) or (statements[m][k] == 1 and is[k])) continue;
              flag = false;
              break;          
          }
        }
        if(flag) ans=  max(ans, num); 
        if(ans == n) return n;
    }
    return ans;
  }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}