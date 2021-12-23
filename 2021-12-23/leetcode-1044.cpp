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
	string ans = "";		
    string longestDupSubstring(string s) {
    	int len = s.size();
    	long long base = 31;
    	vector<ull> hash = vector<ull>(len+1, 0);
    	vector<ull> power = vector<ull>(len+1,0);
    	hash[0] = 0, power[0] = 1;
    	for(int i = 0; i < len; i++){
    		power[i+1] = power[i] * base;
    		hash[i+1] = hash[i] * base + (s[i]-'a') + 1; 
    	}
    	auto check = [&](int inv){
	    	unordered_set<ll> st;
	    	for(int i = 1; i <= len - inv + 1; i++){
	    		ll strHash = hash[i+inv-1] - hash[i-1] * power[inv];
	    		if(st.find(strHash) == st.end()) st.insert(strHash);
	    		else {
	    			ans = s.substr(i-1, inv);
	    			return true;
	    		}
	    	}
	    	return false;
	    };
    	int L = 0, R = len;
    	while(L <= R){
    		int mid = (L + R) >> 1;
    		if(check(mid)) {
    			L = mid + 1;
    		}else R = mid -1;
    	}
    	return ans;
    }

};
int main(int argc, char * argv[]){

	Solution s = Solution();
	cout << s.longestDupSubstring("ababab");
	/* code */


    return 0;
}