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
	long long get(string text ,string pattern){
		vector<long long> dp(text.size(), 0);
		long long ret = 0;
		for(int i = 0; i < text.size(); i++){
			dp[i] = (text[i] == pattern[0]);
			if(i) dp[i] += dp[i-1];
			if(i and text[i] == pattern[1]) ret += dp[i-1]; 
		}
		return ret;
	}
    long long maximumSubsequenceCount(string text, string pattern) {
    	int l1= text.size(), l2 = pattern.size();
    	string t1 = text, t2 = text;
    	t1.insert(t1.begin(), pattern[0]);
    	t2.push_back(pattern[1]);
    	cout << t1;
    	return  max(get(t1, pattern), get(t2, pattern)); 
    }
};


int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}