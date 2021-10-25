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
	set<int> st;
	
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {

    	int n = patience.size();
    	dist[n]; 
    	dist[0] =0 ;
    	for(int i =0 ; i < n; i++) dist[i]= INT_MAX;
    	// memset(dist, INT_MAX, sizeof(dist));
    	vector<vector<int>> mp(n);
    	for(auto edge : edges){
    		mp[edge[0]].push_back(edge[1]);
    	}
    	queue<int> q;
    	q.push_back(0);
    	int curLen = 0, next = 1;
    	while(!q.empty()){
    		for()

    	}

        
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}