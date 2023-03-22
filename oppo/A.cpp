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
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param digits int整型vector 
     * @return int整型
     */
    int maxDigit(vector<int>& digits) {
    	sort(digits.begin(), digits.end());
    	reverse(digits.begin(), digits.end());
    	int ans = 0;
    	for(int i = 0; i < digits.size(); i++){
    		ans = ans * 10 + digits[i];
    	}
    	return ans;
        // write code here
    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}