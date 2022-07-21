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
	int get(vector<int>& nums1, vector<int> &nums2){
    	int len = nums2.size();
    	vector<int> v;

    	int sum = accumulate(nums1.begin(), nums1.end(), 0);
    	for(int i = 0; i < len; i++){
    		v[i] = nums2[i] - nums1[i];
    	}
    	int maxx = 0;
    	for(int i = 0; i < len; i++){
    		if(i){
    			v[i] = max(v[i-1], 0) + v[i];
    		}
    		maxx = max(maxx, v[i]);
    	}
    	return sum + maxx;
	}
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
    	int p1 = get(nums1, nums2);
    	int p2 = get(nums2, nums1);
    	return max(p1, p2);
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}