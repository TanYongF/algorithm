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

unordered_map<int,int> mp;
class Solution {
public:
	vector<vector<int>> g;
	int dfs(int p, vector<int>& quiet){
		if(mp.find(p) != mp.end()) return mp[p];
		int cur = quiet[p];
		for(auto next : g[cur]) cur = min(cur, dfs(next, quiet));
		return mp[p] = cur;
	}
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int len = quiet.size();
        vector<int> ans;
        g = vector<vector<int>>(len);
        for(auto rich : richer) g[rich[1]].push_back(rich[0]);
        for(int i = 0; i < len; i++) ans[i] = dfs(i,quiet);
        return ans;
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
  cout << (nullptr == nullptr) << endl;
	/* code */


    return 0;
}