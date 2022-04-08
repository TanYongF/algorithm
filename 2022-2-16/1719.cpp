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
	    int checkWays(vector<vector<int>>& pairs) {
	      int nodes = INT_MIN;
	      unordered_map<int, set<int>> v;
	      for(auto &pair : pairs){
	        v[pair[0]].insert(pair[1]);
	        v[pair[1]].insert(pair[0]);
	        nodes = max(nodes, pair[1]);
	      }
	      int root = -1;
	      for(int i = 1; i <= nodes; i++){
	        if((int)v[i].size() == nodes-1){ 
	          root = 0;
	          break;
	        }
	      }
	      if(root == -1) return 0;
	      int res = 1;
	      for (auto &[node, neighbours] : v) {
	        if(root == node) continue;
	        int parentDegree = INT_MAX, curParent = -1, curDegree = neighbours.size();
	        for(auto &neighbour : neighbours){
	          if((int)v[neighbour].size() >= curDegree and v[neighbour].size() < parentDegree){
	            parentDegree = v[neighbour].size();
	            curParent = neighbour;;
	          }
	        }
	        if(curParent == -1) return 0;
	        for(auto &neighbour : neighbours){
	          if(neighbour == curParent) continue;
	          if(not v[curParent].count(neighbour)) return 0;
	        }
	        if(parentDegree == curDegree) res = 2;
	      }
	      return res;
	    }
	};
int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}