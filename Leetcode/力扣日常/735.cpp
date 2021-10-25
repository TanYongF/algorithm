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
	vector<int> ans;
    vector<int> asteroidCollision(vector<int>& asteroids) {
    	for(int i = 0; i < asteroids.size(); ++i){
    		if(asteroids[i] < 0){
    			for(int j = i-1; j >= 0; ){
    				if(asteroids[j] < 0) break;
    				if(abs(asteroids[i]) > asteroids[j]){
    					asteroids[j] = 0;
    					j--;
    				}else if(abs(asteroids[i]) == asteroids[j]){
    					asteroids[j] = 0;
    					asteroids[i] = 0;
    					break;
    				}else{
    					asteroids[i] = 0;
    					break;
    				}
    			}
    		}
    	}
    	// for(auto it : asteroids) cout << it << " ";
    	for(int i = 0; i < asteroids.size(); ++i){
    		if(asteroids[i]) ans.push_back(asteroids[i]);
    	}
    	// for(auto it : ans) cout << it << " ";
    	return  ans;
    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	vector<int> test = {5,10,-5};
	s.asteroidCollision(test);
	/* code */


    return 0;
}