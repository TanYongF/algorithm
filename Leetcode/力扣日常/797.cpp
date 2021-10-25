#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <string>
#include <cstring>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <ctime>
#include <climits>
#include <vector>
#include <iostream>
#include <fstream>
#include <list>
#include <iomanip>
#include <numeric>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;
class Solution {
public:
	vector<vector<int>> res;
	vector<int> item;
	unordered_map<int ,vector<vector<int>>> mp;
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    	item.push_back(0);
    	mp = unordered_map<int ,vector<vector<int>>>(graph.size());
    	dfs(0, graph.size(), graph);
    	return res;
    }
    
    vector<vector<int>> dfs(int curNode,int n, vector<vector<int>>& graph){
    	if(mp.find(curNode) != mp.end()) return mp[curNode];
    	vector<vector<int>> res;
    	if(curNode == n-1){
    		vector<int> cur = {1};
    		res.push_back(cur);
    		return res;
    	}

    	for(auto next : graph[curNode]){
    		for(auto node : dfs(next, n, graph)){
    			vector<int> cur = vector<int>(node);
    			cur.insert(cur.begin(), next);
    			res.push_back(cur);
    		}
    	}
    	mp[curNode] = res;
    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}