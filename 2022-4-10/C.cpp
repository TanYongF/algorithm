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
    int maximumProduct(vector<int>& nums, int k) {
    	int mod = 1e9+7;
    	priority_queue<int> pq;
    	for(auto num : nums) pq.push_back(num);
    	for(int i = 0; i < k; i++){
    		int top = pq.top();
    		pq.pop();
    		pq.push(top+1);
    	}
    	long long ans = pq.top();
    	pq.pop();
    	while(not pq.empty() and not ans){
    		ans = ans * (pq.top()) % mod;
    		pq.pop();
    	}
    	return ans;
    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();

    return 0;
}