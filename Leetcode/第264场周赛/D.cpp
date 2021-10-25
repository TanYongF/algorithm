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
	vector<int> degree;
	vector<vector<int>> edges;
	vector<int> dp; 
	queue<int> q;
	int ans = INT_MIN;
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int> dp(n+1, INT_MIN);
        this->degree = vector<int>(n+1,0);
        edges = vector<vector<int>>(n+1);
        for(auto relation : relations){
        	edges[relation[0]].push_back(relation[1]);
        	degree[relation[1]]++;
        }
        for(int i = 1; i <= n; i++) if(not degree[i]) {q.push(i); dp[i] = time[i-1]; ans = max(ans, time[i-1]);}
    	while(not q.empty()){
    		int curNode = q.front();
    		q.pop();
    		for(auto next : edges[curNode]){
    			degree[next]--;
    			if(degree[next] == 0){
    				dp[next] = max(dp[next], dp[curNode] + time[next-1]);
    				q.push(next);
    				ans = max(ans, dp[next]);
    			} 
    		}
    	}
    	return ans;
    }

};
int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}