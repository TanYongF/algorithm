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
    string licenseKeyFormatting(string s1, int k) {
    	string s;
    	for(auto &c : s1){
    		if(c == '-') continue;
    		s +=  (c >= 'a' and c <= 'z') ? (c - 32) : c;
    	}
    	cout << s << endl;
    	int idx = s.size() - k;
    	while(idx > 0){
    		s.insert(idx, "-");
    		idx -= k;
    	}
    	return s;

    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	cout << s.licenseKeyFormatting("2-5g-3-J", 2);
	/* code */


    return 0;
}