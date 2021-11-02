#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <string>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <climits>
#include <vector>
#include <iostream>
#include <bitset>
#include <list>
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
	vector<string> tr;
	unordered_map<char, int> mp;
    vector<string> findWords(vector<string>& words) {
    	tr.push_back("qwertyuiop");
    	tr.push_back("asdfghjkl");
    	tr.push_back("zxcvbnm");
    	int idx = 0 ;
    	for(auto str : words){
    		for(int i = 0; i < str.length(); i++){
    			mp[str[i]] = idx; 
    			mp[str[i]-32] = idx;
    		}
    		idx++;
    	}
    	vector<string> ans;
    	for(auto word : words){
    		if(check(word)) ans.push_back(word);
    	}
    	for(auto it : ans) cout << it; 
    	return ans;

    }
    bool check(string & word){

    	for(int i = 1; i < word.length(); i++){
    		if(mp[i] != mp[i-1]) return false;
    	}
    	return true;
    }

};


int main(int argc, char * argv[]){

	Solution s = Solution();
	vector<string> test = {"Alaska"};
	s.findWords(test);
	/* code */


    return 0;
}