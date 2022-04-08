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
    int minimumFinishTime(vector<vector<int>>& tires, int changeTime, int numLaps) {
    	map<int,int> mp;
    	int ans = 0, n;
    	sort(tires.begin(), tires.end());
    	if(tires[0][0] >= changeTime) return tires[0][0] * numLaps + (numLaps-1) * changeTime;
    	for(auto &tire : tires){
    		if(tires[0][0] > changeTime) break;
    		int need = tire[0], lap = 1, cur = tire[0];
    		while(1){
    			if(need <= changeTime){
    				mp[lap] = min(mp[lap], need);
    				n = max(n, lap);
					cur *= tire[1];
	    			need += cur;
	    			lap++;
    			}else break;
    		}
    	}
		vector<int> dp(n+1, 0);
		for(int i = 1; i <= n; i++){
			for(int j = 0; j <= numLaps and j >= i; j++){
				dp[j] = max(dp[j], dp[j-i] + mp[i]);
			}
		}
		return dp[numLaps];

    	// return 1;    	    
    }

};

int main(int argc, char * argv[]){

	Solution s = Solution();
	// priority_queue <pair<int,int>>	 p;
	// p.push(1);
	// p.push(2);
	// cout << p.top();
	/* code */


    return 0;
}