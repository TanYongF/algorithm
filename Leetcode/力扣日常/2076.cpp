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
	vector<int> father;
	int getFather(int val){
		if(father[val] != val) father[val] = getFather(father[val]);
		return father[val];
	}
	// void union(int n, int m){
	// 	int fatherN = getFather(n);
	// 	int fatherM = getFather(m);
	// 	father[fatherM] = fatherN;
	// }
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
    	father = vector<int>(n);
    	for(int i = 0 ; i < n ; i++) father[i] = i;
        vector<unordered_set<int>> friends(n);
        vector<unordered_set<int>> restrict(n);
        for(int i =0 ; i < n; i++) friends[i].insert(i);
        for(auto restriction : restrictions){
        	restrict[restriction[0]].insert(restriction[1]);
        	restrict[restriction[1]].insert(restriction[0]);
        }
        vector<bool> ans((int)requests.size(), true);
        for(int i = 0; i < (int)requests.size(); i++){
        	int x = getFather(requests[i][0]), y = getFather(requests[i][1]);
        	if(restrict[x].size() < restrict[y].size()) swap(x,y);
        	// if(x < y) swap(x,y);
        	[&]{
	        	for(auto people : restrict[y]){
        			if(friends[x].find(people) != friends[x].end()){
        				ans[i] = false;
        				return;
        			}
        		}
        		father[y] = x;
        		// for(auto people : friends[y]) friends[x].insert(people);
        		friends[x].insert(friends[y].begin(), friends[y].end());
        		restrict[x].insert(restrict[y].begin(), restrict[y].end());
        		// for(auto people : restrict[y]) restrict[x].insert(people);
        		return;
        	}();
        }
        return ans;
    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}