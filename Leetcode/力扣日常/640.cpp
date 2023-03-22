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
    string solveEquation(string equation) {
        int len = equation.size();
        int factorX = 0, factorNum = 0;
        int sign = 0;
        for(int i = 0; i < len; i++){
        	if(equation[i] == '='){
        		sign = 1;
        		if(equation[i+1] == '-'){
        			equation.erase(equation.begin() + i);
        			i--;
        		} 
        		else equation[i] = '-'; 
        	}
        	else if(sign and (equation[i] == '-' or equation[i] == '+'))
        	 equation[i] = equation[i] == '+' ? '-' : '+';
        }
        cout << equation << endl;
        int i = 0, j = 0;
        while(j < len){
        	j = i + 1;
        	while(j < len and equation[j] != '-' and equation[j] != '+') j++;
        	if(j - i > 0){
        		string a = equation.substr(i, j - i);
    			int num = 1;
    			cout << a << endl;
        		if(a.back() == 'x'){
        			if(a == "-") num = -1;
        			else if(a == "+") num = 1;
        			else if(a == "x") num = 1;
        			else num = stoi(a.substr(0, a.size()-1));
        			factorX += num;
        		}else{
        			num = stoi(a);
        			factorNum -= num;
        		}
        	}
        	i = j;
        }
        if(factorX == 0) return "Infinite solutions";
        else return to_string(factorNum / factorX);
        // cout << factorX <<  " .... " <<  factorNum << endl;
        // return "0";
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	string s1 = "x-1=-2x+3";
	s.solveEquation(s1);

	/* code */


    return 0;
}