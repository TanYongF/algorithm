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
    int minimumCost(vector<int>& cost) {
        int len = cost.size();
        int ans = 0;
        sort(cost.begin(), cost.end(), greater<int>());
        for(int i = 0, j = 0; i < len; ){
            j = i;
            if(j + 2 < len){
                ans += (cost[j] + cost[j+1]);
                i = j + 3;
                continue;
            }else if(j + 1 < len){
                ans += (cost[i] + cost[j + 1]);
                i = j + 2;
            }else{
                ans += cost[i];
                i = j + 1;
            }
        }
        return ans;

        
    }
};
int main(int argc, char * argv[]){

    Solution s = Solution();
    /* code */


    return 0;
}