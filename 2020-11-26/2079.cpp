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
    int wateringPlants(vector<int>& plants, int capacity) {
    	long long ans = 0;
    	int len = plants.size();
    	plants.insert(plants.begin(), -1);
    	int last = capacity;
    	for(int i = 1; i <= len ;i++){
    		if(last >= plants[i]){
    			last -= plants[i];
    			ans++;
    		}else{
    			ans += 2 * i - 1;
    			last = capacity - plants[i];	
    		}
    		// cout << i <<  " " << ans << endl;
    	}
    	return ans;
    }
};

int main(int argc, char * argv[]){
vector<int> a= {3,2,4,2,1};
	Solution s = Solution();
	/* code */
s.wateringPlants(a, 6);
    return 0;
}