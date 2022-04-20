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
	bool check(vector<int> &a, vector<int> &b){
		for(int i = 0; i < 5; i++){
			if(a[i] < b[i]) return false;
		}
		return true;
	}
    int perfectMenu(vector<int>& materials, vector<vector<int>>& cookbooks, vector<vector<int>>& attribute, int limit) {
    	int len = cookbooks.size();
    	int happy = 0, healthy = 0;
    	vector<int> a, b;
    	int ans = -1;
    	for(int i = 0; i <= (1 << len) - 1; i++){
    		vector<int> status(5, 0);
    		for(int j = 0; j < len; j++){
    			if(((i >> j) & 1) == 0) continue;
				happy += attribute[j][0];
				healthy += attribute[j][1];
    			for(int k = 0; k < 5; k++) status[k] += cookbooks[j][k];
    		}
    		if(check(materials, status) and healthy >= limit) ans = max(ans, happy);
    	}
    	return healthy;
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}