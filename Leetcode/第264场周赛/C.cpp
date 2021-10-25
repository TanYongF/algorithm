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
typedef pair<int,int> P;

class Solution {
public:
	vector<vector<int>> child;
	long long ans = INT_MIN;
	vector<int> nodeNums;
	int len;
	int sum;
	int ret = 0;
    int countHighestScoreNodes(vector<int>& parents) {
    	len = parents.size();
    	child = vector<vector<int>>(len);
    	nodeNums = vector<int>(len,0);
    	for(int i = 0; i < len; ++i) if(parents[i] != -1) child[parents[i]].push_back(i);
    	dfs(0);
    	sum = nodeNums[0];
    	for(int i = 0; i < len; i++) {
    		long long temp = slove(i);
    		if(temp > ans){
    			ret = 1;
    			ans = temp;
    		}else if(temp == ans) ret++;
    	} 
    	return ret;
    }
   	int dfs(int root){
   		if(not child[root].size()) return (nodeNums[root] = 1);
   		for(int i = 0; i < child[root].size(); i++){
   			nodeNums[root] += dfs(child[root][i]);
   		}
   		return ++nodeNums[root];
   	}
    long long slove(int item){
    	long long  aa = 1;
    	int last = sum;
    	for(int i = 0; i < child[item].size(); i++){
    		aa *= nodeNums[child[item][i]];
    		last -= nodeNums[child[item][i]];
    	}
    	aa *= (last <= 1) ? 1 : (last - 1);
    	return aa;
    }
};
int main(int argc, char * argv[]){


	Solution s = Solution();
	vector<int> test = {-1,2,0,2,0};
	cout << s.countHighestScoreNodes(test);
	/* code */


    return 0;
}