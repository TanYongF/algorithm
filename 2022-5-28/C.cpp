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
    long long maximumImportance(int n, vector<vector<int>>& roads) {
    	vector<int> inDegree(n, 0);
    	for(auto& road : roads){
    		inDegree[road[0]]++;
    		inDegree[road[1]]++;
    	}
    	sort(inDegree.begin(), inDegree.end());
    	long long ans;
    	for(int i = 0; i < n; i++){
    		ans += 1LL* inDegree[i] * (i + 1);
    	}
		return ans;        
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}