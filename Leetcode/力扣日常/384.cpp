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
	int len;
	vector<int> old;
	vector<int> cur;
	int k, tem;
    Solution(vector<int>& nums) {
    	old = nums;
    	cur = nums;
    	len = nums.size();
    }
    
    vector<int> reset() {
    	copy(old.begin(),old.end(), cur.begin());
    	return cur;
    }
    
    vector<int> shuffle() {
    	for(int i = 0; i < len; i++){
    		k =i + rand()%(len - i);
    		swap(cur[i], cur[k]);
    	}
    	return cur;
    }
};


int main(int argc, char * argv[]){

	// Solution s = Solution();
	vector<int> a = {1,2,3};
	Solution s = Solution(a);
	s.shuffle();

	/* code */


    return 0;
}