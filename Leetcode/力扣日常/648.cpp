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
    vector<Trie*> children;
    bool isEnd;
    Trie(){
        children = vector<Trie*>(26);
        isEnd = false;
    }
    void insert(string &s){
        Trie* cur = this;
        for(int i = 0; i < s.size(); i++){
            int index = s[i] - 'a';
            if((cur->children).empty()){
                cur->children[index] = new Trie();
            }
            cur = cur->children[index];
        }
        cur->isEnd = true;
    }
    void convert(string &s){
        Trie* cur = this;
        for(int i = 0; i < s.size(); i++){
            int index = s[i] - 'a';
            if(cur->children[index] == nullptr) return ;
            else{
                cur = cur->children[index];
                if(cur->isEnd){
                    s = s.substr(0, i + 1);
                    return;
                } 
            }
        }
    }
};
class Solution {
public:
    vector<string> split(string &s){
        vector<string> ans;
        int i = 0, j = 0, len = s.size();
        while(j < len){
            while(i < len and s[i] == ' ') i++;
            j = i;
            while(j < len and s[j] != ' ') j++;
            if(i < len and j - i > 0) ans.push_back(s.substr(i, j - i));
        }
        return ans;
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie root = Trie();
        string ans;
        for(auto keyWord : dictionary) root.insert(keyWord);
        vector<string> words = split(sentence);
        for(auto &word : words){
             root.convert(word);
            ans += word + " ";
        }
        ans.pop_back();
        return ans;
    }
};
int main(int argc, char * argv[]){

    Solution s = Solution();
    /* code */


    return 0;
}