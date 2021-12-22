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
    int findRadius(vector<int>& houses, vector<int>& heaters) {
    	sort(heaters.begin(), heaters.end());
    	sort(houses.begin(), houses.end());
    	int L = 0, R = 1e9+10;
    	int ans;
    	while(L <= R){
    		int mid = (L+R) >> 1;
    		if(check(houses, heaters, mid)){
    			R = mid - 1;
    			ans = R;
    		}else{
    			L = mid + 1;
    		}
    	}
    	return ans;
    }
    bool check(vector<int>& houses, vector<int>& heaters, int radis){
    	int i = 0, j = 0;
    	while(i < (int)houses.size() and j < (int)heaters.size()){
    		if(abs(houses[i] - heaters[j]) <= radis) i++;
    		else j++;
    	}
    	return i == (int)houses.size();

    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	



    return 0;
}