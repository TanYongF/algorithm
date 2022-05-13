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
    string largestGoodInteger(string num) {
    	int ch = '.';
    	for(int i = 0; i + 2 < num.size(); i++){
    		if(num[i] == num[i+1] and num[i+1] == num[i+2]){
    			ch = max(ch-'0', num[i]-'0') + '0';
    		}
    	}
    	if(ch == '.') return "";
    	return string(3, ch);
        
    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}