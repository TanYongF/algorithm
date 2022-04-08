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
    int countSubstrings(string s) {
    	int len, ans = 0, im, rm;
    	string t = "$#";
    	for(auto &ch : s) t += ch + "#";
    	t += "!";
    	len = t.size();
    	vector<int> f(len);
    	im = rm = 0;
    	for(int i = 1; i < t.size(); i++){
    		//初始化f[i] f[i] = min(rm - i + 1, f[2 * im - 1]);
    		f[i] = (i <= rm) ? min(rm - i + 1, f[2 * im - i]) : 1;
    		//中心扩展，因为已经增加了$ 和 ! 所以无需判断溢出
    		while(t[i+f[i]] == t[i-f[i]]) ++f[i];
    		//更新最长右端点rm, 和此时的中心位置im
    		if(i + f[i] - 1 > rm){
    			im = i;
    			rm = i + f[i] - 1;
    		}
    		// f[i]-1是最大回文长度，需要向上取整，因此包含回文串的长度为f[i]/2
    		ans += (f[i]/2);
    	}
    	return ans;
    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	cout << s.countSubstrings("tannat");

	/* code */


    return 0;
}