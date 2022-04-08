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
	long long check(vector<int>& time, long long total){
		long long ret;
		for(auto &t : time){
			ret += total / t;
		}
		return ret;
	}
    long long minimumTime(vector<int>& time, int totalTrips) {
    	long long ans;
    	sort(time.begin(), time.end());
    	long long  l = 0, r = time[0] * totalTrips;
    	
    	while(l <= r){
    		long long mid = (l + r) >> 1;
    		if(check(time, mid) >=  1L * totalTrips){
    			ans = mid;
    			r = mid - 1;
    		}else l = mid + 1;
    	}
    	return ans;
        
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}