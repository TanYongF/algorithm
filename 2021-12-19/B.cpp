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
    string addSpaces(string s, vector<int>& spaces) {
    	int len = s.size();
    	string ans = "";
    	sort(spaces.begin(), spaces.end());
    	int j = 0, start = 0, end;
    	for(int j =0; j < spaces.size(); j++){
    		ans += s.substr(start, spaces[j] - start) + " ";
    		start = spaces[j];
    	}
    	ans += s.substr(spaces.back(), s.size() - spaces.back());
    	return ans;

        
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}