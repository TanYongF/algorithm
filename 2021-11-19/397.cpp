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
	unordered_map<int,int> mp;
	int ans = 0;
    int integerReplacement(int n) {
    	mp[1]= 0;
    	return dfs(n);
    }
   	int dfs(int n){
   		if(mp.find(n) != mp.end()) return mp[n];
   		if(n == 1) return 0;
   		if(n % 2 == 0) mp[n] = dfs(n / 2) + 1;
   		else mp[n] = dfs(n-1) + 1;
   	}
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	cout << s.integerReplacement(7);
	/* code */


    return 0;
}


f