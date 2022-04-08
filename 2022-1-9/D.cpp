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
// bool cmp(P p1, P p2){
// 	if(p1.second == p2.second) 
// }
class Solution {
public:
	vector<pair<int,int>> vp;
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
    	for(int i = 0; i < plantTime.size(); i++) vp.push_back({-1 * growTime[i],plantTime[i]});
    	sort(vp.begin(), vp.end());
    	int l = 1, r = INT_MAX;
    	int ans = 0;
    	while(l <= r){
    		int mid = (l + r) >> 1;
    		if(check(mid)) r = mid - 1, ans = mid;
    		else l = mid + 1;
    	}
    	return ans;
    }
    bool check(int day){
    	int curday = 0;
    	for(auto pg : vp){
    		curday += -1 * pg.first;
    		if(curday > day - pg.second) return false; 
    	}
    	return true;

    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}