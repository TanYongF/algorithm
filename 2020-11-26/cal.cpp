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
    stack<char> ops;
    stack<int>  nums;
    unordered_map<char,int> mp = {
  		{'+',1},
        {'-',1},
        {'*',2},
        {'/',2},
        {'%',2},
        {'^',3}
    };
    int calculate(string s) {
        int n = s.size();
        for(int i = 0; i < n; i++){
            if(s[i] == ' '){
                continue;
            }else if(s[i] >= '0' and s[i] <= '9'){
			    long long cur = s[i] - '0';
    			while(i+1 < n and s[i+1] <= '9' and s[i+1] >= '0'){
    				cur = cur * 10 + (s[i+1] - '0');
    				i++;
    			}
    			nums.push(cur);
            }else if(s[i] == '('){
                ops.push('(');
                if(i + 1 < n and ((s[i + 1] == '+' or s[i + 1] == '-'))){
                    nums.push(0);
                    ops.push(s[i+1]);
                    i++;
                }
            }else if(s[i] == ')'){
                while(not ops.empty() and ops.top() != '('){
                    cal();  
                }
                ops.pop();
            }else{
            	while(not ops.empty() and ops.top() != '(' and mp[ops.top()] > mp[s[i]]){
            		cal();
            	}
            	ops.push(s[i]);
            }
        }
        while(not ops.empty() and ops.top() != '('){
            cal();
    	}
        return nums.top();
    }

    void cal(){
        int res;
        int b = nums.top(); nums.pop();
        int a = nums.top(); nums.pop();
        char option = ops.top();  ops.pop();
        switch(option){
            case '+':   res = a + b; break;
            case '-':   res = a - b; break;
            case '*':   res = a * b; break;
            case '/':   res = a / b; break;
            case '%':   res = a % b; break;
            case '^':   res = pow(a,b); break;
        }
        cout <<  a << b << option << res << endl;
        nums.push(res);
    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	string t = " 3+5 / 2 ";
	cout << s.calculate(t);
	/* code */


    return 0;
}