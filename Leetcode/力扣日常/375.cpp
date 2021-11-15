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
    int getMoneyAmount(int n) {
    	int dp[n+2][n+2];
   		memset(dp, 0, sizeof(dp));
   		for(int i = 0; i <= n; i++) dp[i][i] = 0;
   		for(int k = 1; k <= n -1; k++){
   			for(int i = 1; i + k <= n; i++){
   				dp[i][i+k] = INT_MAX;
   				for(int mid = i;mid <= i + k; mid++){
   					dp[i][i + k] = min(dp[i][i+k], mid + max(dp[i][mid-1], dp[mid+1][i + k]));
   				}
   			}
   		}
   		return dp[1][n];
    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	cout << s.getMoneyAmount(10);
	/* code */


    return 0;
}