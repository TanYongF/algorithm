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
    int minSteps(string s, string t) {
    	vector<int> a(26,0);
    	vector<int> b(26,0);
    	for(auto ch : s) a[ch-'a']++;
    	for(auto ch : t) b[ch-'a']++;
    	int ans = 0;
    	for(int i = 0; i < 26; i++){
    		ans += abs(a[i] - b[i]);
    	}
    	return ans;
      
        
    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}