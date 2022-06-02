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
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
    	int len = capacity.size();
    	vector<int> last(len, 0);
    	for(int i = 0; i < len; i++){
    		last[i] = capacity[i] - rocks[i];
    	}
    	sort(last.begin(), last.end());
    	for(int i = 0; i < len; i++){
    		if(additionalRocks > last[i]) additionalRocks -= last[i];
    		else return i;
    	}
    	return len;
  
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	 


    return 0;
} 	