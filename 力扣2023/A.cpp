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
    int minNumBooths(vector<string>& demand) {
    	unordered_set<int> st;
    	vector<int> times(26, 0);
    	for(auto &str : demand){
    		vector<int> cur(26, 0);
    		for(auto &ch : str) cur[ch-'0']++;
    		for(int i = 0; i < 26; i++) times[i] = max(times[i], cur[i]);
    	}
   		return accumulate(times.begin(), times.end(), 0);
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}