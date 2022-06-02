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
    int subarrayBitwiseORs(vector<int>& arr) {
        int len = arr.size();
        int ans = 0;
        int MAXN = 1e9+10;
        vector<bool> v(MAXN, 0);
        unordered_set<int> ost, nst; 
       	for(int i = 0; i < len; i++){
       		for(auto &it : ost){
       			auto status = (it | arr[i]);
       			nst.insert(status);
       			if(v[status] == 0) ans++;
       			v[status] = 1;
       		}
       		nst.insert(arr[i]);;
       		if(v[arr[i]] == 0) 	ans++;
       		v[arr[i]] = 1;
       		ost = nst;
       	}
       	return ans;
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}