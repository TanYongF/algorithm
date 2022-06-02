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
    int maxConsecutive(int bottom, int top, vector<int>& special) {
    	set<int> st;
    	st.insert(bottom-1);
    	st.insert(top+1);
    	for(auto s : special) st.insert(s);
    	int ans = 0;
    	vector<int> v = vector<int>(st.begin(), st.end());
    	int len = v.size();
    	for(int i = 0; i < len-1; i++){
    		ans = max(ans, v[i+1] - v[i] - 1);
    	}
    	return ans;
        
    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}