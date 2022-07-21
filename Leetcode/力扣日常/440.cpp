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
    int findKthNumber(int n, int k) {
    	int curr = 1;
    	k--;
    	while(k > 0){
    		int step = getSteps(curr);
    		if(step > k){
    			k -= step;
    			curr++;
    		}else{
    			curr *= 10;
    			k--;
    		}
    	}
    	return curr;

    }

    int getSteps(int cur, int n){
    	int first = cur;
    	int last  = cur;
    	int ans = 0;
    	while(first <= n){
    		ans = min(n, last) - first + 1;
    		first = first * 10;
    		second = first * 10 + 9;

    	}
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}