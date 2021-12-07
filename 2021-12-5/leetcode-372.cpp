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
	ll binpowmod(ll a, ll b, const int & mod){
		ll ans = 1;
		while(b){
			if(b & 1) ans = ans * a % mod;
			a = a * a % mod;
			b >>= 1;
		}
		return ans;
	}
    int superPow(int a, vector<int>& b) {
    	int mod = 1337;
    	if(a == 1) return 1;
    	ll cur = a, ans = 1; 
    	for(int i = b.size()-1; i >= 0; i--){
    		ans = ans * binpowmod(cur, 1LL * b[i],  mod);
    		cur = binpowmod(cur, 10, mod);
    	}
    	return (int)ans;
    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	// cout << s.binpowmod(2,10,341);
	vector<int> v= {1,0};
	cout << s.superPow(2, v);
	/* code */


    return 0;
}