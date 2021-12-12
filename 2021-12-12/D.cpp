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
const int MAXN = 2e5 + 10;
int a[MAXN];
ll preAdd[MAXN];
class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
    	int len = (fruits.back())[0];
    	memset(a, 0, sizeof(a));
		memset(preAdd, 0, sizeof(preAdd));    
		preAdd[0] = a[0];
    	for(auto fruit : fruits) a[fruit[0]] = fruit[1];
    	for(int i = 1; i <= len; i++){
    		preAdd[i] = preAdd[i-1] + a[i];
    	}
    	for(int i =0; i <= len ;i++) cout << preAdd[i] << " ";
    		cout << endl;
    	int ans = INT_MIN, last;
    	int cur;
    	int left = max(startPos - k , 0), right = min(len, startPos + k);
    	// cout << left << right << endl;
    	for(int l = left; l <= startPos; l++){
    		last = k, cur = 0;
    		cur = preAdd[startPos] - (l == 0 ? 0 : preAdd[l-1]);
    		last -= 2 * (startPos - left);
    		if(last <= 0){
    			ans = max(ans, cur);
    			break;
    		}
    		int r = min(len, startPos + r);
    		cur += preAdd[r] - preAdd[startPos];
    		ans = max(ans, cur);
    	}
    	cout << ans;
    	for(int r = right; r >= startPos; r--){
    		// cout << "in";
    		last = k, cur = 0;
    		cur = preAdd[r] - (startPos == 0 ? 0 : preAdd[startPos-1]);
    		cout << cur;
    		last -= 2 * (r - startPos);
    		if(last <= 0){
    			ans = max(ans, cur);
    			break;
    		}
    		if(startPos > 0){
	    		int l = max(0, startPos - cur);
	    		cur += preAdd[startPos] - preAdd[l];
	    		ans = max(ans, cur);
    		}

    	}
    	 return ans;
    }
  
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	vector<vector<int>> v =  {{2,8},{6,3},{8,6}};
	cout << s.maxTotalFruits(v, 5 ,4);
	/* code */


    return 0;
}