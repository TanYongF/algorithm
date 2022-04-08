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
  string repeatLimitedString(string s, int repeatLimit) {
    vector<int> mp(26,0);
    for(auto ch : s)  mp[ch-'a']++;
    string ans = "";
    int cur;
    for(int i = 25; i >= 0; i--){
      if(mp[i] == 0) continue;
      cur = 0;
      for(int k = 0; k < mp[i]; k++){
        ans += i + 'a';
        cur++;
        if(cur == repeatLimit){
          bool flag = false;
          for(int  j = i - 1; j >= 0; j--){
            if(mp[j] > 0){
              mp[j]--;
              ans += j + 'a';
            }
          }
          if(not flag) return ans;
          else cur = 0;
        }
      }
      
    }
    return ans;
  }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	// s.countEven(11);
	/* code */


    return 0;
}