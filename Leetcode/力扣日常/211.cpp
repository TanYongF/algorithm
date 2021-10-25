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
struct TrieNode{
	vector<TrieNode*> child;
	bool isEnd;
	TrieNode(){
		this->child = vector<TrieNode*>(26,nullptr);
		this->isEnd = false;
	}

};
void insert(TrieNode *root, const string &word){
	TrieNode *node = root;
	for(auto c : word){
		if(node->child[c - 'a'] == nullptr) node->child[c-'a'] =new TrieNode();
		node = node->child[c - 'a'];
	}
	node -> isEnd = true;
}
class WordDictionary {
public:
	TrieNode * rooter;
    WordDictionary() {
    	rooter = new TrieNode();
    }
    
    void addWord(string word) {
    	insert(rooter, word);
    }
    
    bool search(string word) {
    	return dfs(rooter, word, 0);

    }
   	bool dfs(TrieNode *root, string &word,int curIdx){
   		if(curIdx == word.size()){
   			return root->isEnd;
   		}
   		char ch = word[curIdx];
   		if(ch >= 'a' && ch <= 'z'){
   			TrieNode* child = root->child[ch - 'a'];
   			if(child != nullptr && dfs(child, word, curIdx+1)) return true;
   		}else if(ch == '.'){
   			for(int i = 0; i < 26; i++){
   				TrieNode* child = root->child[i];
   				if(child != nullptr && dfs(child, word, curIdx + 1)) return true;
   			}
   		}
   		return false;
   	}
};
int main(int argc, char * argv[]){

	// Solution s = Solution();
	WordDictionary w = WordDictionary();
	w.addWord("tanyongfeng");
	cout << w.search("tanyongfeng");
	/* code */


    return 0;
}