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
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {

    	vector<int> ans;
  		int len = security.size();
  		vector<int> a(len), b(len);
  		a[0] = 1;
  		b[len-1] = 1;
  		for(int i = 1; i < len; i++){
  			if(security[i] <= security[i-1]) a[i] = a[i-1] + 1;
  			else a[i] = 0; 
  		}
  		for(int i = len-2; i >= 0; i++){
  			if(security[i] <= security[i+1]) b[i] = b[i+1] + 1;
  			else b[i] = 0;
  		}
  		for(int i = time;  i <= len - 1 - time; i++){
  			if(a[i-1] >= time and b[i+1] >= time) ans.push_back(i);
  		}   
  		return ans;   
    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}