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
    bool checkValid(vector<vector<int>>& matrix) {
    	int n = matrix.size();
    	// vector<bool> has(n, false);
    	// unordered_map<int,int> 
    	unordered_set<int> st;
    	vector<vector<int>> v;

    	for(int i = 0; i < n; i++){
    		st = unordered_set<int>();
    		for(int j = 0; j < n; j++){
    			if(st.find(matrix[i][j]) != st.end()) return false;
    			else st.insert(matrix[i][j]);
    		}
    	}

    	for(int i = 0; i < n; i++){
    		st = unordered_set<int>();
    		for(int j = 0; j < n; j++){
    			if(st.find(matrix[j][i]) != st.end()) return false;
    			else st.insert(matrix[j][i]);
    		}
    	}
    	return true;
        
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}