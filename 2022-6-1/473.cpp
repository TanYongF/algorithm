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
    // vector<int> status;
    // int need;
    // bool ans = false;
    // void dfs(int start, int len, int state){
    //     if(len == 4){
    //         if(state == need) ans = true;
    //         return;
    //     }
    //     if(start >= status.size()) return; 
    
    //     //not get
    //     dfs(start + 1, len + 1, state);
        
    //     // get
    //     if(state & status[start]) return;
    //     dfs(start + 1, len + 1, state | status[start]);
    // }
    // bool makesquare(vector<int>& matchsticks) {
    //     int len = matchsticks.size();
    //     // int avg = accumulate(matchsticks.begin(), matchsticks.end(), ) / 4;
    //     need = (1 << len) - 1;
    //     for(int i = 1; i < (1 << len); i++){
    //         int lens = 0;
    //         for(int j = 0; j < len; j++){
    //             if((i >> j) & 1) lens += matchsticks[j];
    //         }
    //         if(lens == avg) status.push_back(i); 
    //     }
    //     dfs(0, 0, 0);
    //     return ans;
    // }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */
    map<int,int> mp;
    mp[1] = 1;
    mp[4]= 1;
    mp[3] =1;
    for(auto it : mp){
        cout << it.first << endl;;
    }


    return 0;
}