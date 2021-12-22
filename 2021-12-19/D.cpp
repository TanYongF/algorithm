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
    int lengthOfLIS(vector<int>& nums) {
        int len = 1, n = (int)nums.size();
        if (n == 0) {
            return 0;
        }
        vector<int> d(n + 1, 0);
        d[len] = nums[0];
        for (int i = 1; i < n; ++i) {
            if (nums[i] >= d[len]) {
                d[++len] = nums[i];
            } else {
                int l = 1, r = len, pos = 0; // 如果找不到说明所有的数都比 nums[i] 大，此时要更新 d[1]，所以这里将 pos 设为 0
                while (l <= r) {
                    int mid = (l + r) >> 1;
                    if (d[mid] < nums[i]) {
                        pos = mid;
                        l = mid + 1;
                    } else {
                        r = mid - 1;
                    }
                }
                d[pos + 1] = nums[i];
            }
        }
        return len;
    }
    int kIncreasing(vector<int>& arr, int k) {
        int len = arr.size();
       	int maxx = len + len + 1;
       	for(auto a : arr) maxx =max( maxx, a);
       	vector<vector<int>> v;
       	for(int i = 0; i < k; i++){
       		vector<int> tem;
       		for(int j = i; i < len; i+=k){
       			tem.push_back(arr[j]);
       		}
       		v.push_back(tem);

       	}
       	int ans = 0;
       	for(auto &vv : v){
       		ans += v.size() - lengthOfLIS(vv);
       	}
       	return ans;

    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}