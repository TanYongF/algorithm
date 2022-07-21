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
    long long countPairs(int n, vector<vector<int>>& edges) {
    	vector<bool> has(n, false);
    	vector<vector<int>> g = vector<vector<int>>(n);
    	for(auto &edge : edges){
    		g[edge[0]].push_back(edge[1]);
    	}
    	long long ans =  n* (n-1);
    	for(int i = 0; i < n; i++){
    		if(has[i]) continue;
    		queue<int> q;
    		long long item = 1;
    		q.push(i);
    		has[i] = true;
    		while(not q.empty()){
    			int cur = q.front();
    			q.pop();
    			for(auto next : g[cur]){
    				if(not has[next]){
    					q.push(next);
    					has[next] = true;
    					item++;
    				} 
    			}
    		}
    		ans -= item * (item-1);
    	}
    	return ans / 2;        
    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}