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
	vector<string> split(const string &str, char &flag){
	    int i = 0, j = 0;
	    vector<string> ans;
	    while(i < str.length() and j < str.length()){
	        while(i < str.length() and str[i] == flag) i++;
	        j = i;
	        while(j < str.length() and str[j] != flag) j++;
	        if(i < str.length()) ans.push_back(str.substr(i, j - i));
	        i = j;
	    }
	    return ans;
	}
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
    	map<string, int> mp;
    	set<string> ans;
    	int maxWord = 0;
    	char ch = ' ';
    	for(int i = 0; i < messages.size(); i++){
    		auto &message = messages[i];
    		auto words = split(message, ch);
    		mp[senders[i]] += words.size();
    		if(mp[senders[i]] == maxWord) ans.insert(senders[i]);
    		else if(mp[senders[i]] > maxWord){
    			ans.clear();
    			ans.insert(senders[i]);
    			maxWord = mp[senders[i]];
    		}
    	}
    	return *ans.rbegin();
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}