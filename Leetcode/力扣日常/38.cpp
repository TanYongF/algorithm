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
    string countAndSay(int n) {
    	string pre = "1";
    	string cur;
    	if(n == 1) return pre;
    	for(int i = 2; i <= n; i++){
    		cur = ""; 
    		int len = pre.length(),k;
    		for(int start = 0; start < len; start = k){
    			k = start;
    			while(k < len and pre[k] == pre[start]){
    				k++;
    			}	
    			cur += to_string(k - start) + pre[start];
    		}
    		pre = cur;
    	}
    	return cur;

    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	// for(int i = 1 ;i < 10; i++){
		cout << s.countAndSay(4);
	// }
	/* code */


    return 0;
}