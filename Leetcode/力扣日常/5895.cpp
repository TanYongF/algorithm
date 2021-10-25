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
    int minOperations(vector<vector<int>>& grid, int x) {
    	int m = grid.size(), n = grid[0].size(), ans = 0;
        const int len = m * n;
        vector<int> temp(len);
        int idx = 0;
        for(auto g : grid)  for (auto it : g) temp[idx++] = it;

        sort(temp.begin(), temp.end());

    	idx = ceil(1.0 * len / 2) - 1;
    	 // cerr << len << " " << idx;
        // cout << temp[idx] << endl;
    	for(int i = 0; i < len; i++){
    		if(i == idx) continue;
    		if(abs(temp[idx] - temp[i]) % x != 0) return -1;
    		ans += (abs(temp[idx]- temp[i]) / x);
    	}
    	// cout << ans;
    	return ans;
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	cout << ceil(2/4);
	vector<vector<int>> t= {{146}};
	s.minOperations(t, 86);
	/* code */


    return 0;
}