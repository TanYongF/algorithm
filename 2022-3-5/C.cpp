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
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
    	vector<int> in(n, 0);
    	unordered_map<int,vector<int>> mp;
    	for(auto &edge : edges){
    		in[edge[1]]++;
    		mp[edge[0]].push_back(edge[1]);
    	}
    	queue<int> q;
    	vector<set<int>> ans(n);
    	for(int i = 0; i < n; i++) if(in[i] == 0) q.push(i); 

    	while(q.empty()){
    		int cur = q.front();
    		q.pop();
    		unordered_set<int> st;
    		for(auto &next : mp[cur]){
    			ans[next].insert(cur);
    			for(auto &parent : ans[cur]) ans[next].insert(parent);
    			in[next]--;
    			if(not in[next]) q.push(next);
    		}

    	}

    	vector<vector<int>> ret(n, vector<int>());
    	for(int i = 0; i < n; i++){
    		ret[i] = vector<int>(ans[i].begin(), ans[i].end());
    	}
    	return ret;
        
    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}