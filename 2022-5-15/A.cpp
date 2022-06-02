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
    vector<string> removeAnagrams(vector<string>& words) {
    	vector<string> sorted;
    	for(auto word : words){
    		sort(word.begin(), word.end());
    		sorted.push_back(word);
    	}
    	vector<string> ans;
    	for(int i = 0; i < words.size(); i++){
    		if(not i){
    			ans.push_back(words[i]);
    		}else{
    			if(sorted[i] != sorted[i-1]) ans.push_back(words[i]);
    		}

    	}
    	return ans;
        
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}