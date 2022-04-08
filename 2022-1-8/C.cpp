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
    int longestPalindrome(vector<string>& words) {
    	unordered_map<string, int> mp;
    	int ans= 0;
        for(auto &word : words) mp[word]++;
    	for(auto& it : mp){
    		string cur = it.first;
    		if(cur[0]==cur[1]) continue;
    		// string need = "" +to_string(cur[1]) + cur[0];
            string need{cur[1],cur[0]};
            // cout << cur << need;
    		if(mp.find(need) != mp.end()){
    			ans += 4 * min(mp[need], mp[cur]);
    			mp[need] = -1;
    		}
    		mp[cur] = -1;
    	}
    	bool flag = false;
    	for(auto& it : mp){
    		if(it.second == -1) continue;
    		string cur = it.first;
    		if(mp[cur] % 2 == 0) ans += mp[cur] / 2 * 4;
    		else if(mp[cur] == 1) flag = true;
    		else {
    			ans += mp[cur] / 2 * 2;
    			flag = true;
    		}
    	}
    	if(flag) ans += 4;
    	return ans;
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}