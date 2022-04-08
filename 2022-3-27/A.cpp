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
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
    	vector<vector<int>> ans;
    	set<int> st1(nums1.begin(), nums1.end()), st2(nums2.begin(), nums2.end());
    	vector<int> item1, item2;
    	for(auto num : st1){
    		if(not st2.count(num)) item1.push_back(num);
    	}
    	for(auto num : st2){
    		if(not st1.count(num)) item2.push_back(num);
    	}
    	ans.push_back(item1);
    	ans.push_back(item2);
    	return ans;
        
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}