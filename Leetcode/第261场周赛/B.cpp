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
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
    	int cur = 0, m = rolls.size();
    	int sum =  mean * (m + n);
    	for(auto it : rolls){
    		cur += it;
    	}
    	vector<int> ans(n,1);
    	if(cur >= sum) return {};
    	int last = sum - cur;
    	if(last > 6 * n || last < n) return {};
    	last -= n;
    	for(int i = 0; i < n && last != 0; i++){
    		while(ans[i] < 6 && last != 0){
    			ans[i]++;
    			last--;
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