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
    string multiply(string num1, string num2) {
    	int n1 = num1.size(), n2 = num2.size();
    	vector<long long> ans(n1 + n2, 0);
    	for(int i = n2 - 1; i >= 0; i--){
    		for(int j = n1 - 1; j >= 0; j--){
    			int curBit = (num2[i] - '0') * (num1[j] - '0');
    			int offset = (n2 - 1 - i) + (n1 - 1 - j);
    			// cout << offset << endl;
    			ans[n1+n2-1-offset] += curBit; 
    		}
    	}
    	int carry = 0;
    	int j = n1 + n2 -1;
    	for(; j >= 0; j--){
    		int curBit = ans[j] + carry; 
    		carry = curBit / 10;
    		ans[j] = curBit % 10;
    	}

    	string str;
    	j = 0;
    	while(ans[j] == 0) j++;
    	for(; j < n1 + n2; j++) str += to_string(ans[j]);
    	return str.empty() ? "0" : str;
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	string s1 = "0";
	string s2 = "1234234248";
	cout << s.multiply(s1, s2);
	/* code */


    return 0;
}