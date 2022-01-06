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

struct Trie{
	bool isEnd;;
	vector<Trie *> child;
	Trie(){
		this->child = vector<Trie*>(26, nullptr);
		this->isEnd = false;
	}
};
class Solution {
public:
	Trie* root = new Trie();
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        // int len = words.size();
        sort(words.begin(), words.end(), [&](const string &a1, const string &a2){
        	return a1.size() < a2.size();
        });
        vector<string> ans;
        for(string word : words){
        	if(word.length() == 0) continue;
        	else if(dfs(word, 0)){
        		ans.push_back(word);
        	}else insert(word);
        }   
        // for(auto it : ans) cout << it << " "; 
        return ans;
    }
    bool dfs(const string &s, int startPos){
    	Trie *cur = root;
    	if(startPos == (int)s.size()) return true;
    	for(int i = startPos; i < (int)s.size(); i++){
 			int index = s[i] - 'a';
 			cur = cur -> child[index];
 			if(cur == nullptr) return false;
 			else{  
 				if(cur -> isEnd) if(dfs(s, i + 1)) return true;
 			}
    	}
    	return false;
    }
    void insert(const string &s){
    	Trie *cur = root;
    	for(int i = 0; i < (int)s.size(); i++){
    		int index = s[i] - 'a';
    		if(cur -> child[index] == nullptr) cur -> child[index] = new Trie();
    		cur = cur -> child[index];
    	}
    	cur -> isEnd = true;
    	return;
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	vector<string> test = {"test","t","est"};
	s.findAllConcatenatedWordsInADict(test);
	// hash_set<int> st;
	/* code */


    return 0;
}