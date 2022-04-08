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
	unordered_set<string> st1;
	unordered_set<string> st2;
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
    	int len = startWords.size();
    	int ans= 0;
    	for(int i = 0; i < len; i++){
    		sort(startWords[i].begin(), startWords[i].end());
    		st1.insert(startWords[i]);
    		vector<bool> has(26, false);
    		for(auto ch : startWords[i]){
    			has[ch-'a'] = true;
    		}
    		string cur;
    		for(int j = 0; j < 26; j++){
    			if(not has[j]) {
    				cur = startWords[i] + string(1,('a' + j)); 
    				sort(cur.begin(), cur.end());
    				st1.insert(cur);
    			}
    		}
    	}

    	for(auto &word : targetWords){
    		sort(word.begin(), word.end());
    		if(st1.find(word) != st1.end()) ans++;
    	}
    	return ans;


        
    }

};
int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}