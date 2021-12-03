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
    int largestSumAfterKNegations(vector<int>& nums, int k) {
    	unordered_map<int,int> mp;
    	for(auto num : nums) mp[num]++;
    	int ans = accumulate(nums.begin(), nums.end(), 0);
   		for(int i = -100; i <= -1; i++){
   			if(mp[i]){
   				int op = min(mp[i], k);
   				k -= op;
   				mp[i] -= op;
   				mp[-1 * i] += op;
   				ans += 2 * i * op;
   				if(k == 0) return ans;
   			}
   		}
   		if(k % 2 == 0 or mp[0]) return ans;
   		for(int i = 1; i <= 100; i++){
   			if(mp[i]){
   				return ans - 2 * i;
   				break;
   			}
   		}
   		return 0;
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}