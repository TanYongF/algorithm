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
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
    	int len  = recipes.size();
    	bool ok = true;
    	unordered_map<string, bool> mp;
    	for(auto supply : supplies) mp[supply] = true;
    	vector<bool> has(len, false);
    	while(ok){
    		ok = false;
    		for(int i = 0; i < len ; i++){
    			if(has[i]) continue;
    			else{
    				bool can = true;
    				for(auto &need : ingredients[i]){
    					if(mp.find(need)==mp.end()){
    						can = false;
    						break;
    					}
    				}
    				if(can) {
    					mp[recipes[i]] = true;
    					has[i] = true;
    					ok = true;
    				}
    			}
    		}
    	}
    	vector<string> ans;
    	for(int i = 0; i < len; i++) if(has[i]) ans.push_back(recipes[i]);
        return ans;
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}