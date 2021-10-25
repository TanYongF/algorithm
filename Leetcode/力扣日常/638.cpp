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
	map<vector<int>, int> mp;
	// vector<int> need;
	int len, specialNum;
	vector<int> price;
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
    	this->price = price; 
    	len = price.size();
    	vector<vector<int>> filterSpecial;
    	for(auto& spe : special){
    		int curPrice = 0, curCount = 0;
    		for(int i = 0; i < (int)spe.size()-1; i++) curPrice += spe[i] * price[i], curCount += spe[i];
    		if(curCount > 0 and spe[len] < curPrice) filterSpecial.push_back(spe);
    	}
    	specialNum = filterSpecial.size();
    	return dfs(needs, filterSpecial);
    	// return mp[needs];
    }
    int dfs(vector<int> &curNeeds, vector<vector<int>> &filterSpecial){
    	if(mp.find(curNeeds) != mp.end()) return mp[curNeeds];
		int maxNeed = 0;
		for(int i =0; i < len; i++) maxNeed += curNeeds[i] * price[i];
		mp[curNeeds] = maxNeed; 
    	for(int i = 0; i < specialNum; i++){
    		bool canPull = true;
    		for(int j = 0; j < len; j++)
    			if(curNeeds[j] < filterSpecial[i][j]){canPull = false ; break;}
    		if(canPull){
    			vector<int> nextNeeds = del(curNeeds, filterSpecial[i]);
    			mp[curNeeds] = min(mp[curNeeds], dfs(nextNeeds, filterSpecial));
    		}

    	}
    }
    vector<int> del(vector<int>& v1, vector<int>& v2){
    	vector<int> ret;
    	// int len  = v1.size();
    	for(int i = 0; i < (int)v1.size(); i++){
    		ret.push_back(v1[i] - v2[i]);
    	}
    	return ret;
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}