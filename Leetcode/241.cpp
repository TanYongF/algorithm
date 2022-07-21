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
    unordered_map<string, unordered_set<int>> mp;
    bool check(const string& str){
    	if(str.size() <= 2) return true;
    	else return false;
    }
    void backtrace(const string &str){
    	if(mp.count(str)) return;
    	if(check(str)){
    		mp[str].insert(stoi(str));
    		return;
    	}
    	for(int i = 0; i < str.size(); i++){
    		if(str[i] > '9' or str[i] < '0'){
    			string left = str.substr(0, i);
    			string right = str.substr(i + 1);
    			backtrace(left);
    			backtrace(right);
    			for(auto &lv : mp[left]){
    				for(auto &rv : mp[right]){
		    			if(str[i] == '*')		mp[str].insert(lv * rv);
		    			else if(str[i] == '+')  mp[str].insert(lv + rv);
		    			else if(str[i] == '-')  mp[str].insert(lv - rv);
    				}
    			}
    		}
    	}
    }
    vector<int> diffWaysToCompute(string expression) {
    	backtrace(expression);
    	return vector<int>(mp[expression].begin(), mp[expression].end());
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();


    return 0;
}