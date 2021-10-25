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
    string toHex(int num) {
    	if(num == 0) return "0";
    	string ans = "";
    	int idx = 0;
    	for(int i = 0; i < 8; i++){
    		string curbit;
    		int cur = (num >> (4 * i)) & 0xf;
    		curbit = cur < 10 ? (cur + '0') : (cur - 10 + 'a');
    		ans = curbit + ans;
    	}
    	size_t pos = ans.find_first_not_of('0');
    	ans.erase(ans.begin(), ans.begin() + pos);
    	return ans;

    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	cout << s.toHex(1) << endl;
	cout << s.toHex(26) << endl;
	cout << s.toHex(-1);
	cout << s.toHex(-1);
	/* code */


    return 0;
}