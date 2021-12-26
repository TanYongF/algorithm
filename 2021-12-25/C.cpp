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
    bool canBeValid(string s, string locked) {
    	if(s.size() % 2 != 0) return false;
    	int len = s.size();
    	for(int i = 0; i < len ;i++) if(locked[i] == '0') s[i] = ' ';
    	vector<int> left(len, 0);
    	vector<int> right(len, 0);
    	vector<int> spaceL(len,0);
    	vector<int> spaceR(len,0);
    	for(int i = 0 ; i < len; i++){
    		if(i==0){
    			if(s[i] == ' ') spaceL[i] = 1;
    		}else{
    			spaceL[i] = spaceL[i-1];
    			if(s[i] == ' ') spaceL[i]++;
    		}

    		if(i == 0) {if(s[i] == '(') left[i] = 1;}
    		else{
    			if(s[i] == '(') left[i] = left[i-1] + 1; 
    			else left[i] = left[i-1];
    		} 
    	}
    	for(int i = len -1; i >= 0; i--){
    		if(i==len-1){
    			if(s[i] == ' ') spaceR[i] = 1;
    		}else{
    			spaceR[i] = spaceR[i+1];
    			if(s[i] == ' ') spaceR[i]++;
    		}
    		if(i == len -1){
    			if(s[i] == ')') right[i] = 1;
    		}else{
    			right[i] = right[i+1];
    			if(s[i] == ')') right[i]++;
    		}
    	}
    	int leftSize = 0, rightSize = 0;
    	for(int i = 0; i < len; i++){
    		if(s[i] == ')'){
    			rightSize++;
				if(i == 0) return false;
				else if(left[i-1] + spaceL[i-1] < rightSize) return false;
    		}
    	}
    	for(int j = len-1; j >= 0; j--){
    		if(s[j] == '('){
    			leftSize++;
    			if(j == len-1) return false;
    			else if(right[j+1] + spaceR[j+1] < leftSize) return false;
    		} 
    	}
    	return true;

        
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}