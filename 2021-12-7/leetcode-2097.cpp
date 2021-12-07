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
	vector<vector<int>> ans;
	unordered_map<int,int> inDeg, outDeg;
	unordered_map<int, vector<int>> g;
	void dfs(int curNode){
		while(not g[curNode].empty()){
			int next = g[curNode].back();
			g[curNode].pop_back();
			dfs(next);
			ans.push_back({curNode, next});
		}
	}
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
    	unordered_set<int> st;
    	for(auto pair : pairs){
    		outDeg[pair[0]]++;
    		inDeg[pair[1]]++;
    		st.insert(pair[0]);
    		st.insert(pair[1]);
    		g[pair[0]].push_back(pair[1]);
    	}
    	int start = inDeg.begin()->first;
    	for(auto it : st){
    		if(inDeg[it] < outDeg[it]) start = it;
    	}
    	cout << start << endl;
    	dfs(start);
    	
    	reverse(ans.begin(), ans.end());
    	for(auto a : ans) cout << a[0] << " " << a[1] << endl; 
    	return ans;
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	vector<vector<int>> v = {{5,1},{4,5},{11,9},{9,4}};
	s.validArrangement(v);
	/* code */
    return 0;
}