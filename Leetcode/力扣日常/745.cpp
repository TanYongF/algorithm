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
class WordFilter {
public:
    unordered_map<string, int> mp1;
    WordFilter(vector<string>& words) {
        int index = 0;
    	for(auto &word : words){
            for(int i = 0; i < word.size(); i++){
                for(int j = word.size()-1; j >= 0; j--){
                    string prefix = word.substr(0, i + 1);
                    string suffix = word.substr(j);
                    string tartget = prefix + "#" + suffix;
                    mp1[tartget] = index;
                }
            }
            index++;
    	}
    }
    
    int f(string pref, string suff) {
        string target = pref + "#" + suff;
        return mp1.count(tartget) ? mp1[tartget] : -1;
    }
};


/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */
int main(int argc, char * argv[]){

	// Solution s = Solution();
	/* code */


    return 0;
}