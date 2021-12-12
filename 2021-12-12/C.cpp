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
    int countPoints(string rings) {
    	int len = rings.size();
    	int  n = len / 2;
    	int a[n][3];
    	memset(a,0, sizeof(a));
    	int j= 0;
    	for(int i = 0; i < len; i+=2){
    		char c = rings[i];
    		int idx = rings[i+1] - '0';
    		if(c=='R') a[idx][0] = 1;
    		else if(c == 'G') a[idx][1] = 1;
    		else if(c == 'B') a[idx][2] = 1;
    	}
    	int ans = 0;
    	for(int i = 0; i < n; i++){
    		bool flag = true;
    		for(int j = 0; j < 3; j++) if(a[i][j] == 0) flag = false;
    		if(flag) ans++;
    	}
    	return ans;
    }
};


int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}