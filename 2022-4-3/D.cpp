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
class Trie{
public:
    bool flag = false;
    Trie* next[26] = {nullptr};

    Trie(){}  
        Trie* node = this;
        for(int i=0; i<word.length(); i++){
            char c = word[i];
            if(node->next[c-'a']==nullptr){
                node->next[c-'a'] = new Trie();
            }
            node = node->next[c-'a'];
        }
        node->flag = true; 
    }
};
class Encrypter {
public:
	unordered_map<char, string> keyIdx;
	unordered_map<string, vector<char>> valueIdx;
	unordered_set<string> dict; 
	Trie obj = Trie();
	int ans;
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
    	for(int i = 0; i < keys.size(); i++) keyIdx[keys[i]] = values[i];
    	for(int i = 0; i < dictionary.size(); i++) obj.insert(dictionary[i]);
    	for(int i = 0; i < values.size(); i++) valueIdx[values[i]].push_back(keys[i]);
    }
    
    string encrypt(string word1) {
    	string ans = "";
    	for(auto &ch : word1) ans += keyIdx[ch];
    	return ans;
    }
    
    int decrypt(string word2) {
    	ans = 0;
    	unordered_set<Trie*> oldst, newst;
    	if(word2.size() & 1) return 0;
    	oldst.insert(&obj);
    	for(int i = 0; i < word2.size(); i+=2){
    		newst.clear();
    		string value = word2.substr(i, 2);
    		for(auto *cur : oldst){
	    		for(auto key : valueIdx[value]){
	    			if(cur -> next[key-'a']) newst.insert(cur->next[key-'a']);
	    		}
    		}
    		oldst = newst;
    	}
      
      for(auto node : newst) if(node->flag) ans++;
      return ans;;
    }
};
int main(int argc, char * argv[]){

	// Solution s = Solution();
	/* code */


    return 0;
}