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
    int beautifulBouquet(vector<int>& flowers, int cnt) {
    	int i = 0, j = 0, n = flowers.size();
    	long long ans = 0;
    	int mod = 1000000007;
    	unordered_map<int,int> mp;
    	for(; j < n; j++){
    		mp[flowers[j]]++;
    		while(i <= j and mp[flowers[j]] > cnt){
    			mp[flowers[i]]--;
    			i++;
    		}
    		long long inv = j - i + 1;
    		ans = (ans + inv) % mod;
    	}
    	return ans;
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}