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
    vector<string> cellsInRange(string s) {
    	vector<string> ans;
    	char start = s[0], end = s[3];
    	int spos =  s[1]-'0', epos = s[4]-'0';
    	for(int i = 0;  i <= (start-end); i++){
    		// string te
    		for(int j = spos; j <= epos; j++){
    			string temp;
    			temp.push_back(start+i);
    			temp.push_back('0' + j);
    			ans.push_back(temp);
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