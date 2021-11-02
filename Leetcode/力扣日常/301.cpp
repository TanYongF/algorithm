#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <string>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <climits>
#include <vector>
#include <iostream>
#include <bitset>
#include <list>
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
	int leftLast= 0 , rightLast = 0;
	bitset<25> state;
	unordered_set<string> st;

	vector<string> ans;
    vector<string> removeInvalidParentheses(string s) {
    	getMinOperation(s);
    	cout << leftLast << " " << rightLast << endl;
    	backTrace(s, 0, 0, 0);

    	ans.assign(st.begin(), st.end());
    	    	for(auto it : ans) cout << it << endl;
    	cout << "--------";
    	return ans;
    	// return nullptr;
    	// for()

    }
    void backTrace(string &s , int curIdx,  int leftDel, int rightDel){

    	if(leftDel > leftLast or rightDel > rightLast) return;
    	if(curIdx == (int)s.length()){
    		cout << 1;
	    	if(leftDel == leftLast and rightDel == rightLast){
	    		// if(check(state)) as.push_back(getV(state));
	    		check(state, s);
	    		cout << state << endl;
	    	}

	    	return;
    	}
    	if(s[curIdx] == ')'){
    		state[curIdx] = 1;
    		backTrace(s, curIdx+1, leftDel, rightDel);

    		state[curIdx] = 0;
    		backTrace(s, curIdx + 1, leftDel, rightDel+1);
    	}else if(s[curIdx] == '('){
    		state[curIdx] = 1;
    		backTrace(s, curIdx + 1, leftDel, rightDel);

    		state[curIdx] = 0;
    		backTrace(s,curIdx + 1, leftDel+1, rightDel);
    	}else{
    		state[curIdx] = 1;
    		backTrace(s, curIdx+ 1, leftDel, rightDel);
    	} 

    }
    void getMinOperation(string &s){
    	for(int i = 0; i < (int)s.size(); i++){
    		if(s[i] == '(') leftLast++;
    		if(s[i] == ')'){
    			if(leftLast > 0) leftLast--;
    			else rightLast++;
    		}
    	}
    }
    void check(bitset<25> &state, string &str){
    	string ans = "";
    	int left = 0, right = 0;
    	for(int i = 0; i < (int)str.size(); i++){
    		if(state[i] and str[i] == '('){
    			left++;
    			ans += str[i];
    		} 
    		if(state[i] and str[i] == ')'){
    			ans += str[i];
    			if(left > 0) left--;
    			else right++;
    		}else if(str[i] != ')' and str[i] != '(') ans += str[i];
    	}
    	if((not left) and (not right)) st.insert(ans);
    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	string s1= "()())()";
	s.removeInvalidParentheses(s1);
	/* code */


    return 0;
}