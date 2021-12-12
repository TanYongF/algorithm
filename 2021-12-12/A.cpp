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
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
    	int len = plants.size();
    	int ans = 0;
    	int f = 0, e = len - 1, a = capacityA, b = capacityB;
    	while(f <= e){
    		if(f == e) if(plants[f] > max(a, b)) ans += 1;
    		else{
	    		if(a >= plants[f]) a-= plants[f];
	    		else {
	    			a = capacityA - plants[f];
	    			ans++;
	    		}

	    		if(b >= plants[e]) b -= plants[e];
	    		else{
	    			b = capacityB - plants[e];
	    			ans++;
	    		} 	
    		}

    		f++;
    		e--;
    	}
    	return ans;
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}