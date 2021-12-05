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
    vector<int> findEvenNumbers(vector<int>& digits) {
    	int len = digits.size();
    	sort(digits);
    	set<int> st;
    	for(int i = 0; i < len; i++){
    		if(digits[i] == 0) continue;
    		if(i != 0 and digits[i] == digits[i-1]) continue;
    		for(int j = 0; j < len; j++){
    			if(i == j ) continue;
    			for(int k = 0; k < len; k++){
    				if(k == i || k == j) continue;
    				string tem = to_string(digits[i]) + to_string(digits[j]) + to_string(digits[k]);
    				int num = stoi(tem);
    				if(num % 2 == 0) st.insert(num);
    			}
    		}
    	}
    	vector<int> ans = vector<int>(st.begin(), st.end());
    	return ans;
        
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}