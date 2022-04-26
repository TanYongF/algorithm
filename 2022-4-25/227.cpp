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
	stack<int> nums;	
	stack<char> op;
	int len;
	unordered_map<char, int> mp = {
            {'+',1},
            {'-',1},
            {'*',2},
            {'/',2},
            {'%',2},
            {'^',3}
	};
    int calculate(string str) {
    	len = str.size();
    	nums.push(0)
    	for(int i = 0; i < len; i++){

            //ch == ' '
            if(str[i] == ' ') continue;

    		// ch == '('
    		if(str[i] == '('){
    			op.push('(');
    			// '(-' or '(+'
    			if(str[i+1] == '-' or str[i+1] == '+'){
    				nums.push(0);
    				op.push(str[i+1]);
    				i++;
    			}
    		}
    		// ch == digit
    		else if(str[i] >= '0' and str[i] <= '9'){
    			long long cur = str[i] - '0';
    			while(i+1 < len and str[i+1] <= '9' and str[i+1] >= '0'){
    				cur = cur * 10 + (str[i+1] - '0');
    				i++;
    			}
    			nums.push(cur);
    		}

    		// ch == ')'
    		else if(str[i] == ')'){
    			while(not op.empty() and op.top()!='('){
    				cal();
    			}
    			op.pop();
    		}

    		// ch == operation
    		else{
    			while(not op.empty() and op.top() != '(' and mp[op.top()] >= mp[str[i]]){
    				cal();
    			}
    			op.push(str[i]);
    		}
    	}
    	while(not op.empty() and op.top() != '('){
    		// cout << 111 << endl;
    		cal();
    	}
    	return nums.top();
    }
    void cal(){
        long long b = nums.top(); nums.pop();
        long long a = nums.top(); nums.pop();
        char oper = op.top(); op.pop();
        long long res;
        switch (oper) {
            case '+':   res = a + b; break;
            case '-':   res = a - b; break;
            case '*':   res = a * b; break;
            case '/':   res = a / b; break;
            case '%':   res = a % b; break;
            case '^':   res = pow(a,b); break;
        }
        nums.push(res);
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	cout << s.calculate("-2+1");
	/* code */


    return 0;
}