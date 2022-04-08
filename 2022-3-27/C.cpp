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
    vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
    	vector<long long> ans;
    	long long temp = 1;
    	if(intLength & 1) temp = pow(10, intLength/2-1);
    	else temp  = pow(10, intLength/2);
    	for(auto &k : queries){
	    	if(intLength & 1){
	    		temp += k-1;
	    		string out = to_string(temp), out2(out.rbegin(), out.rend());
	    		ans.push_back(stol(out + out2.substr(1)));
	    	}else{
	    		temp += k-1;
	    		string out = to_string(temp), out2(out.rbegin(), out.rend());
	    		ans.push_back(stol(out + out2.substr(1)));
	    	}
    	}
    	return ans;
        
    }
};
int main(int argc, char * argv[]){

	// Solution s = Solution();
	cout << ((-1 + 1ll) / 2) << endl;
	/* code */


    return 0;
}