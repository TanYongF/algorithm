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
#include <numeric>
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
    int findMinMoves(vector<int>& machines) {
    	int avg,ans = -1, sum = 0, len = machines.size();
    	vector<int> preAdd(len);
    	for(auto& it : machines) sum+=it;
    	if(sum % len != 0) return -1;
      avg =  sum / len;
    	partial_sum(machines.begin(), machines.end(), preAdd.begin());
      // for(auto it :preAdd) cout << it << " " ;
    	for(int i = 0; i < len; i++){
        //左边需要转入数量
        int left = max(0, i * avg - preAdd[i] + machines[i]);
        //右边需要转入的数量
        int right = max(0, (len - i -1) * avg - (preAdd[len-1] - preAdd[i]));
        // cout << left << " " << right << endl;
        ans = max(ans, left + right);
      }
      return ans;
    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
  vector<int> t = {1,0,5};
  cout << s.findMinMoves(t);
	/* code */


    return 0;
}