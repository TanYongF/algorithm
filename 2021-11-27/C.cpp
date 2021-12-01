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
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int sx = startPos[0], sy = startPos[1];
        int hx = homePos[0],  hy = homePos[1];
        int ans = 0;
        if(sx > hx) swap(sx, hx);
        if(sy > hy) swap(sy, hy);
        for(int i = sx; i <= hx; i++) ans += rowCosts[i];
        for(int j = sy; j <= hy; j++) ans += colCosts[j];
        ans = ans - rowCosts[startPos[0]] - colCosts[startPos[1]];
       	return ans;
    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}