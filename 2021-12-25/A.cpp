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
    int mostWordsFound(vector<string>& sentences) {
    	vector<int> idx;
    	for(int i = 0; i < sentences; i++){
    		if(sentences[i] == ' ') idx.push_back(i);
    	}
    	int i = 0, j = 0;
    	// while(j < sentences.size()){
    	// 	if(sentences[j] == )
    	// }
    	map<string,int> mp;
    	for(int i = 0; i < idx.size(); i++){
    		

    	}
        
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}