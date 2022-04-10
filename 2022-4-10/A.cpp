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
    int largestInteger(int num) {
    	string s = to_string(num);
    	vector<int> a, b;
    	for(auto ch : s){
    		if((ch-'0') % 2) a.push_back(ch-'0');
    		else b.push_back(ch-'0');
    	}
    	sort(a.begin(), a.end(), greater<int>());
    	sort(b.begin(), b.end(), greater<int>());
    	int m = 0, n = 0;
    	string ans;
    	for(int i = 0; i < num; i++){
    		if((s[i]-'0')%2) ans.push_back(a[m++]);
    		else ans.push_back(b[n++]);
    	}
    	return stoi(ans);        
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}