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
	const int nums[10] = {0, 3, 3, 3, 3, 3, 3, 4, 3, 4};
	const int mod = 1e9+7;
	const int MAXN  = 1e5+10;
	vector<long long> dp1 = vector<long long>(MAXN, 0);
	vector<long long> dp2 = vector<long long>(MAXN, 0);
	void getWays(int m){
		dp1[0] = dp2[0] = 1;
		for(int i = 1; i <= m; i++){
			for(int j = 1; j <= min(i, 3); j++){
				dp1[i] += dp1[i-j];
			}
			// cout << dp1[i] << endl;	
		}
		for(int i = 1; i <= m; i++){
			for(int j = 1; j <= min(i, 4); j++){
				dp2[i] += dp2[i-j];
			}
		}
	}
    int countTexts(string pressedKeys) {
    	long long ans = 1;
    	int len = pressedKeys.size();
    	getWays(len);	
    	// cout << dp2[10];
    	int i = 0, j = 0;
    	while(j < len){
    		while(j < len and pressedKeys[j] == pressedKeys[i]) j++;
    		if(nums[pressedKeys[i]-'0'] == 4) ans = ans *  dp2[(j - i)] % mod;
    		else ans = ans * dp1[(j-i)] % mod; 
    		i = j;
    	}
    	return ans;
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	s.countTexts("fafa");
	/* code */


    return 0;
}