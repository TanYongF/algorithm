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
    int findJudge(int n, vector<vector<int>>& trust) {
    	unordered_map<int,int> mp(n);
    	vector<vector<int>> v(n);
    	for(auto tt : trust){
    		mp[tt[1]]++;
    		v[tt[0]].push_back(tt[1]);
    	}
    	for(auto it : mp){
    		if(it.second == n - 1){
    			if(v[it.first].size() == 0) return it.first;
    		}
    	}
    	return -1;
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	



    return 0;
}