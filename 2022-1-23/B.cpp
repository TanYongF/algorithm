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
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
    	int minn = INT_MAX, maxx = INT_MIN;
       	int cur = 0;
        for(auto diff : differences){
        	cur += diff;
        	minn = min(minn, cur);
        	maxx = max(maxx, cur);
        }
        int l = lower - minn, r = upper - maxx;
        return r - l >= 0 ? r - l : 0;
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}