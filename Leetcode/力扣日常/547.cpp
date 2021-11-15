#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <string>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <climits>
#include <vector>
#include <iostream>
#include <bitset>
#include <list>
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
	vector<int> father;
	getFather(int val){
		if(father[val] != val) father[val] = getFather(father[val]);
		return father[val];
	}
	void unionSet(int m, int n){
		int fatherM = getFather(m);
		int fatherN = getFather(n);
		father[fatherN] = fatherM;
	}
    int findCircleNum(vector<vector<int>>& isConnected) {
    	int len = isConnected.size();
    	father = vector<int>(len);
    	for(int i =0 ; i < len; i++) father[i] = i;
    	for(int i =0 ; i< len; i++){
    		for(int j = 0; j < len; j++){
    			if(isConnected[i][j]) unionSet(i,j);
    		}
    	}
    	// unordered_set<int> st;D
    	int ans = 0;
    	for(int i =0 ; i < len; i++) if(father[i] == i) ans++;
		return ans;
    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}