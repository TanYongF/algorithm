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
	vector<bool> has;
	vector<vector<int>> g;
	int cur = 0;

	void dfs(int node){
		cur++;
		for(auto next : g[node]){
			if(not has[next]) dfs(next);
		}
	}
    int maximumDetonation(vector<vector<int>>& bombs) {
    	int len = bombs.size();
    	int ans = 0;
     	g = vector<vector<int>>(len);
    	for(int i = 0; i < len; i++){
    		for(int j = 0;  j < len; j++){
    			if(i == j) continue;
    			long long r2 = 1ll * (bombs[i][0]- bombs[j][0])* (bombs[i][0]- bombs[j][0]) 
    			 + 1ll * (bombs[i][1]- bombs[j][1])*(bombs[i][1]- bombs[j][1]); 
                if(r2 <= 1LL * bombs[i][2] * bombs[i][2] or r2 <= 1LL * bombs[j][2] * bombs[j][2]){
                	g[i].push_back(j);
                }
    		}
    	}
    	for(int i = 0; i < len; i++){
    		cur = 0;
    		has = vector<bool>(len, false);
    		dfs(i);
    		ans = max(ans, cur);
    	}
    	return ans;
       
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();


    return 0;
}