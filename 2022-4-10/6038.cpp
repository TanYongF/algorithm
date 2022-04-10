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
    string minimizeResult(string expression) {
    	int plusIdx = 0, left, right, first , second, third, four, a, b, ans = INT_MAX;
    	while(expression[plusIdx] != '+') plusIdx++;
    	for(left = 0; left < plusIdx; left++){
    		if(left == 0) first = 1;
    		else first = stoi(expression.substr(0, left));
    		second = stoi(expression.substr(left, plusIdx - left));
    		for(right = plusIdx + 1; right < expression.size(); right++){
    			third = stoi(expression.substr(plusIdx + 1, right - plusIdx));
    			if(right == expression.size()-1) four = 1;
    			else four = stoi(expression.substr(right + 1));
    			if(first * (second + third) * four < ans){
    				a = left, b = right;
    				ans = first * (second + third) * four;
    			}
    		}
    	}
    	string ret = expression.substr(0, a) + "(" + expression.substr(a, b-a+1) + ")" + expression.substr(b+1);
    	return ret;        
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	cout << s.minimizeResult("247+38");
	/* code */


    return 0;
}