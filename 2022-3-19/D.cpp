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
	void get(string& floor, int carpetLen){
		int i = 0, j = 0, cur = 0, maxx, start = 0;
		for(; j < carpetLen; j++){
			if(floor[j] == '0') cur++;
		}
		maxx = cur;
		for(;j < floor.size(); j++){
			if(floor[j] == '0') cur++;

			if(floor[i] == '0') cur--;
			i++;

			if(cur > maxx)	start = i, maxx = cur;
		}
		for(int k = 0; k < carpetLen; k++){
			floor[k+start] = '1';
		}
	}	
    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
    	while(numCarpets--) get(floor, carpetLen);
    	int ans = 0;
    	for(auto ch : floor) if(ch == '0') ans++;
        return ans;
    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}