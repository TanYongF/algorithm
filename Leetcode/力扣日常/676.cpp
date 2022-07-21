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
    Trie* children[26];
    bool isEnd = false;
};


class MagicDictionary {
public:
    Trie *root = new Trie();
    void insert(string &s){
        Trie* cur = root;
        for(int i = 0; i < s.size(); i++){
            if(not cur->children[s[i]-'a']) cur->children[s[i]-'a'] = new Trie();
            cur = cur->children[s[i]-'a'];
        }
        cur->isEnd = true;
    }

    void buildDict(vector<string> dictionary) {
        for(auto &s : dictionary)  insert(s);
    }
    
    bool search(string searchWord) {
        bool can = false;
        Trie *cur = root;
        int i, j, len = len;
        for(i = 0; i < len; i++){
            if(cur->children[searchWord[i]-'a']) cur = cur->children[searchWord[i]-'a'];
            else break;
        }
        for(j = 0; j < 26; j++){
            if(cur->children[j]){
                i++;
                cur = cur->children[j];
                for(; i < len; i++){
                    if(cur->children[searchWord[i]-'a']) cur = cur->children[searchWord[i]-'a'];
                    else break;
                }  
                if(cur->isEnd and i == len) return can;
            }
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */
int main(int argc, char * argv[]){

	// Solution s = Solution();
	/* code */


    return 0;
}