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
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
    	int len = tiles.size();
    	vector<int> starts;
    	vector<long long> pre(len, 0); 
    	sort(tiles.begin(), tiles.end());
    	for(int i = 0; i < len; i++){
    		pre[i] = 1;
    		starts.push_back(tiles[i][0]);
    		if(i) pre[i] += pre[i-1] + (tiles[i-1][1] - tiles[i-1][0]);
    	} 

    	long long ans = INT_MIN;
    	for(int i = 0; i < len; i++){
    		int tail = starts[i] + carpetLen - 1;
    		auto it = upper_bound(starts.begin(), starts.end(), tail);
    		int idx = distance(starts.begin(), it) - 1;
    		long long preSum = pre[idx] - pre[i];
    		long long last = min(1LL * tiles[idx][1] - tiles[idx][0] + 1, 1LL *carpetLen - preSum);
    		ans = max(ans, preSum + last);
    	}
    	return ans;
    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}