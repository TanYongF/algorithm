#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <string>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <climits>
#include <vector>
#include <iostream>
#include <bitset>
#include <list>
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
	int nodeSize =0, ret = INT_MIN;
	int maxTime;
	vector<vector<pair<int,int>>> mp;
	vector<bool> hasVisted;
	vector<int> values;
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
    	nodeSize = values.size();
    	this->maxTime = maxTime;
    	this->values = values;
    	hasVisted = vector<bool>(nodeSize);
    	
    	mp =  vector<vector<pair<int,int>>>(nodeSize);
    	for(auto edge : edges){
    		mp[edge[0]].push_back({edge[1], edge[2]});
    		mp[edge[1]].push_back({edge[0], edge[2]});
    	}
    	dfs(0, 0, 0);
        return ret; 
    }
    void dfs(int curNode, int curTime, int curValue){
    	// cout << curNode << " " << curTime << " " << curValue << endl;;
    	if(curTime > maxTime) return;
    	if(curNode == 0) ret = max(ret, curValue);
    	for(auto next : mp[curNode]){
    		if(not hasVisted[next.first]){
    			hasVisted[next.first] = true;
    			dfs(next.first, curTime + next.second, curValue + values[next.first]);
    			hasVisted[next.first] = false;
    		}else{
    			dfs(next.first, curTime + next.second, curValue);
    		}
    	}
    }
};

int main(int argc, char * argv[]){
	Solution s = Solution();
	/* code */
	vector<int> values = {0,32,10,43};
	vector<vector<int>> edges = {{0,1,10},{1,2,15},{0,3,10}}; 
	int maxTime = 49;
	cout <<	s.maximalPathQuality(values , edges, maxTime);

	


    return 0;
}