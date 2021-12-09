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
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int len = nums.size();
     	vector<int> pre(len, 0), sum;
     	partial_sum(nums.begin(), nums.end(), pre.begin());
     	sum.push_back(pre[k-1]);
     	for(int i = 1; i < len; i++) if(i + k - 1 < len) sum.push_back(pre[i+k-1]-pre[i-1]);
     	len = sum.size();
     	// for(auto it : sum) cout << it << " ";
     	// 	cout << endl;
     	vector<int> left(len,0), right(len,len-1);
     	for(int i = 1; i < len; i++){
     		if(sum[i] > sum[left[i-1]]) left[i] = i;
     		else left[i] = left[i-1];
     	}
     	for(int i = len-2; i >= 0; i--){
     		if(sum[i] > sum[right[i+1]]) right[i] = i;  
     		else right[i] = right[i+1];
     	}
     	// for(auto it : left) cout << it << " ";
     	// cout << endl;
     	// for(auto it : right) cout << it <<  " ";
     	// 	cout << endl;
     	int maxx = INT_MIN, l, r, mid;
     	for(int i = k; i < len - k; i++){
     		int cur = sum[i] + sum[left[i-k]] + sum[right[i+k]];
     		if(cur > maxx){
     			mid = i;
     			l = left[i-k];
     			r = right[i+k];
     			maxx = cur;
     		}
     	}
     	// cout << l << mid << r;
     	vector<int> ans = {l, mid, r};
     	return ans;
    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	vector<int> v= {1,2,1,2,6,7,5,1};
	s.maxSumOfThreeSubarrays(v, 2);
	/* code */


    return 0;
}