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
	bool check(string s){
		bool ok = false;
		int i =  0, j = s.length()-1;
		while(i <= j){
			if(s[i] != s[j]){
				// ok = false;
				return false;
			}
		}
		return true;
	}
    string firstPalindrome(vector<string>& words) {
    	for(auto word : words){
    		if (check(word))
    		{
 					return word;   			/* code */
    		}
    	}
    	return " ";
        
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}