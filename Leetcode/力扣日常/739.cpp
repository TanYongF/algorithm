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
    vector<int> dailyTemperatures(vector<int>& temperatures) {
    	int size =temperatures.size();
    	vector<int> ans(size,0);
    	stack<pair<int,int>> sk;
    	temperatures.push_back(INT_MIN);
    	sk.push({INT_MAX, -1});
    	for(int i = 0; i < temperatures.size(); i++){
    		while(sk.top().first < temperatures[i]){
    			ans[sk.top().second] = i - sk.top().second;
    			sk.pop();
    		}
    		sk.push({temperatures[i],i});
    	}
    	// temperatures.erase(temperatures.end()-1);
    	for(auto it : ans) cout << it ;
    	return ans;
    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	vector<int> temperatures = {73,74,75,71,69,72,76,73};
	s.dailyTemperatures(temperatures);
	/* code */


    return 0;
}