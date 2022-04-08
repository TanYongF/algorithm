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
const int MAXN = 2e4 + 10;
class Solution {
public:

    string subStrHash(string s, int power, int mod, int k, int hashValue) {
    	int len = s.size();
    	ll pmd[MAXN];
    	pmd[0] = 1;
    	ll cuh = 0;
    	int start = -1;
    	for(int i = 1; i < MAXN; i++) pmd[i] = pmd[i-1] * power % mod;
    	for(int i = len - k; i < len; i++){
    		cuh = (cuh + ((s[i]-'a'+1) * pmd[i-len+k]) % mod) % mod;
    		if(cuh == hashValue and i + k - 1 < len) start = i;
    	}
    	// cout << cuh;
    	for(int i = len - k - 1; i >= 0; i--){
    		cuh = (cuh - ((s[i + k]-'a'+1)*pmd[k-1]) % mod) % mod;
    		if(cuh < 0) cuh += mod;
    		cuh = ((s[i]-'a'+1) + (cuh * power % mod)) % mod;
    		if(cuh == hashValue and i + k - 1 < len) start = i;
    	}

    	if(start == -1) return "";
    	else return s.substr(start, k);
        
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	string ss= "leetcode";
	cout << s.subStrHash(ss,7,20,2,0);
	/* code */


    return 0;
}