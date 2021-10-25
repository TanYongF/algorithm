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
    int minimumMoves(string s) {
    	int ans = 0;
    	for(int i = 0; i < s.length() - 2;){
    		if(s[i] == 'O') i++;
    		if(s[i] == 'X') {
    			ans++;
    			i+=3;
    		}
    	}
    	return ans;
        
    }
};


int main(int argc, char * argv[]){

	Solution s = Solution();
	s.minimumMoves("XXOX");
	/* code */


    return 0;
}