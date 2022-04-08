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
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
    unordered_map<int,int> x, y, xy;
    // unordered_map<int,set<int>> noxy;
    vector<int> ans;
    for(auto &lamp : lamps){
      x[lamp[0]]++;
      y[lamp[1]]++;
      xy[abs(lamp[0]-lamp[1])]++;
    }
	for(auto &query : queries){
        bool can = true;
        int qx = query[0], qy = query[1];
        if(x.count(qx) or y.count(qy) or xy.count(abs(qx-qy))) can = true;
        else can = false;

        for(int i = -1; i <= 1; i++){
            for(int j = -1; j <= 1; j++){
            	if(x.count(qx+i)){
            		x[qx+i]--;
            		if(not x[qx+i]) x.erase(qx+i);
            	}
            	if(y.count(qy+i)){
            		y[qx+i]--;
            		if(not y[qy+j]) y.erase(qy+i);
            	}
            	int dg = abs(qx+i-qy-j);
            	if(xy.count(dg)){
            		xy[dg]--;
            		if(not xy[dg]) xy.erase(dg);
            	}
            }
        }	
        ans.push_back((can ? 1 : 0));
        }
        return ans;
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}