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
	bool check(vector<int>& candies, int value, long long k){
		long long cur = 0;
		for(auto &candy : candies){
			cur = cur + 1LL * (candy / value);
			if(cur >= k) return true;
		}
		return cur >= k;
	}
    int maximumCandies(vector<int>& candies, long long k) {
    	int left = 1,right = 1e7+10;
    	long long sum = 0;
    	for(auto &candy : candies) sum += candy;
    	if(sum < k) return 0;
    	int ans;
    	while(left <= right){
    		int mid = (left + right) >> 1;
    		if(check(candies, mid, k)){
    			ans = mid;
    			left = mid + 1;
    		}else right = mid - 1;
    	}  
    	return ans; 
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}