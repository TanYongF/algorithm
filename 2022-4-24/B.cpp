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
struct pair_hash {
    inline std::size_t operator()(const std::pair<int,int> & v) const {
        return v.first*31+v.second;
    }
};
class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) {
        unordered_set<pair<int,int>, pair_hash> st;
        for(auto &circle : circles){
        	int a = circle[0], b = circle[1], r = circle[2];
        	for(int i = a - r ; i <= a + r; i++){
        		for(int j = b - r; j <= b + r; j++){
        			if((i - a)*(i-a) + (j - b)*(j - b) <= r * r) st.insert({i, j});
        		}
        	}
            
        }
        return st.size();
        
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}