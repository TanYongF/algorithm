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
    int maxProduct(vector<string>& words) {
    	int len = words.size();
    	vector<bitset<26>> vs;
    	int ret = 0;
    	for(int i = 0; i < len;i++){
    		bitset<26> bit;
    		for(auto &ch : words[i]) bit[ch - 'a'] = 1;
    		vs[i] = bit;
    	}
    	for(int i = 0; i < len; i++){
    		for(int j = i + 1; j < len; j++){
    			if((vs[i]^vs[j]) == (vs[i]|vs[j])) ret = max(ret, (int)words[i].length()* (int)words[j].length());
    		}
    	}
    	return ret;

    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}