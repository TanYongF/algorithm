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
bool cmp(pair<char, int> p1, pair<char, int> p2){
  return p1.second > p2.second;
}
class Solution {
public:               
    string longestDiverseString(int a, int b, int c) {
      string ans = "";
      int cl;
      vector<pair<char,int>> nums = {{'a',a}, {'b', b}, {'c',c}};
      while(true){
      	// cout << ans.size();
      	// cout << ans << ?endl;
        sort(nums.begin(), nums.end(), cmp);
        cl = ans.size();
        if(nums[0].second == 0) break;
        if(cl == 0) ans += nums[0].first;
        else{
          for(int i = 0; i < 3 and nums[i].second > 0 ; i++){
            if(cl >= 2 and ans[cl-1] == nums[i].first and ans[cl-2] == nums[i].first) continue;
            else{
              ans += nums[i].first;
              nums[i].second--;
              break;
            }
          }
        }
        if(cl == (int)ans.size()) break;
      }
      return ans;
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	cout << s.longestDiverseString(1,2,7);
	



    return 0;
}