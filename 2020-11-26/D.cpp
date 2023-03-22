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


bool cmp(vector<int> p1, vector<int> p2){
	if(p1[0] != p2[0]) return p1[0] < p2[0];
	else return p1[1] > p2[1];
}
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param redpockets int整型vector<vector<>> 
     * @return int整型
     */
    int maxRedpockets(vector<vector<int> >& redpockets) {
        // write code here
        sort(redpockets.begin(), redpockets.end(), cmp);
       	vector<int> dp;
       	int ans = 0;
       	for(auto redpocket : redpockets){
       		int w = redpocket[0], h = redpocket[1];
       		if(dp.empty() or h > dp.back())dp.push_back(h);
       		else{
       			auto it = lower_bound(dp.begin(), dp.end(), h);
       			int idx = distance(dp.begin(), it);
       			dp[idx] = h;
       		}
       		ans = max(ans, dp.size());
       	}
        return ans;
    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}