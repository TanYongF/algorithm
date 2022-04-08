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
    int getKthElement(const vector<int>& nums1, const vector<int>& nums2, int k) {
    	int m = nums1.size(), n = nums2.size();
    	int index1 = 0, index2 = 0;
    	while(1){
    		if(index1 == m) return nums2[index2 + k - 1];
    		if(index2 == n) return nums1[index1 + k - 1];
    		if(k == 1) return min(nums1[index1], nums2[index2]);

    		int newIndex1 = min(index1 + (k / 2 - 1), m-1);
    		int newIndex2 = min(index2 + (k / 2 - 1), n-1);
    		int pivot1 = nums1[newIndex1], pivot2 = nums2[newIndex2];
    		if(pivot1 <= pivot2){ 
    			k -= (newIndex1 - index1 + 1);
    			index1 = newIndex1 + 1;
    		}else{
    			k -= (newIndex2 - index2 + 1);
    			index2 = newIndex2 + 1;
    		}
    	}

    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
      int totalLength = nums1.size() + nums1.size();
      if(totalLength & 1){
        return findKthArrays(nums1, nums2, totalLength / 2 + 1);
      }else return (findKthArrays(nums1, nums2, totalLength / 2) + findKthArrays(nums1, nums2, totalLength / 2 + 1)) / 2.0;
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}