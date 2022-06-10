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
    int shipWithinDays(vector<int>& weights, int days) {
        int len = weights.size();
        int ans = 0;
        int l = 0, r = accumulate(weights.begin(), weights.end(), 0);
        while(l <= r){
            int mid = (l + r) >> 1;
            auto check = [&]()->bool{
                int need = 0, cur = 0;
                for(int i = 0; i < len; i++){
                    if(cur < weights[i]){
                        cur = mid - weights[i];
                        need++;
                    }else cur -= weights[i]; 
                }
                return need <= days;
            };
            if(check()){
                ans = mid;
                r = mid - 1;
            }else l = mid + 1;
        }
        return ans;
    }
};
int main(int argc, char * argv[]){

    Solution s = Solution();
    /* code */


    return 0;
}