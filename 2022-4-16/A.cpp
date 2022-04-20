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
    int giveGem(vector<int>& gem, vector<vector<int>>& operations) {
    	for(auto &operation : operations){
    		int need = gem[operation[0]] / 2;
    		gem[operation[0]] -= need;
    		gem[operation[1]] += need;
    	}
    	sort(gem.begin(), gem.end());
    	return gem.back() - gem[0];
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}