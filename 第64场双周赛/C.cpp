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
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
    	set<int> add;
    	int len = s.length();
    	set<int, greater<int>> del;
    	int preAdd[len];
    	memset(preAdd,0, sizeof(preAdd));
    	for(int i =0; i < s.size(); i++){
    		preAdd[i] = i >= 1 ? preAdd[i-1] : 0;
    		if(s[i] == '|') {
    			add.insert(i);
    			del.insert(i);
    			preAdd[i]++;
    		}
    	}
    	vector<int> ans;
    	for(auto& query : queries){
    		auto start = add.lower_bound(query[0]);
    		auto end   = del.lower_bound(query[1]);
    		if(start == add.end() or end == del.end()){
    			ans.push_back(0);
    			continue;
    		}
    		int ret = *end - *start - 1;
    		ret = ret - (preAdd[*end] - preAdd[*start] - 1);
    		ret = ret >= 0 ? ret : 0;
    		ans.push_back(ret);
    	}
    	return ans;  
    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	vector<vector<int>> test =  {{1,17},{4,5},{14,17},{5,11},{15,16},{1,2}};
	s.platesBetweenCandles("***|**|*****|**||**|*", test);
	/* code */


    return 0;
}