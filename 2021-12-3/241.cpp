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
	unordered_map<string,vector<int>> mp;
	int len;
	bool check(const string& s){
		if(s.size() == 1) return true;
		else if(s.size() == 2 and  s[0] >= '0' and s[0] <= '9' and s[1] >= '0' and s[1] <= '9') return true;		
		return false;
	}
	void backtrace(string expression){
		if(mp[expression].size() != 0) return;
		// cout << expression << endl;
		if(check(expression)){
			mp[expression].push_back(stoi(expression));
			return;
		}
		for(int i = 0 ; i < (int)expression.size(); i++){
			if(expression[i] < '0' or expression[i] > '9'){
				string left = expression.substr(0, i), right = expression.substr(i+1);
				backtrace(left);
				backtrace(right);
				for(auto &t1 : mp[left]){
					for(auto &t2 : mp[right]){
						if(expression[i] == '-') mp[expression].push_back(t1 - t2);
						else if(expression[i] == '+') mp[expression].push_back(t1 + t2);
						else mp[expression].push_back(t1 * t2);
					}
				}
    		}
		}
	}
    vector<int> diffWaysToCompute(string expression) {
    	len = expression.size();
    	backtrace(expression);
    	auto ans = vector<int>(mp[expression].begin(), mp[expression].end());
    	for(auto it : mp){
    		cout << it.first << ":" << endl;
    		for(auto it2 : it.second) cout << it2 << " ";
    			cout << endl;
    	}
    	return ans;
    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	string str = "2-42*54-4";
	s.diffWaysToCompute(str);
	/* code */


    return 0;
}