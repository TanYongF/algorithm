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
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
    	priority_queue<int> pq;
    	int fuel = startFuel, curr, prev = 0;
    	int len = stations.size();
    	int ans = 0;
    	for(int i = 0; i <= len; i++){
    		curr = (i < len) ? stations[i][0] : target;
    		fuel -= (curr - prev);
    		while(fuel < 0 and not pq.empty()){
    			fuel += pq.top();
    			pq.pop();
    			ans++;
    		}
    		if(fuel < 0){
    			return -1;
    		}
    		if(i < len){
    			pq.push(stations[i][1]);
    			prev = curr;
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