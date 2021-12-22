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
typedef pair<int,int> P;
bool cmp(P p1, P p2){
	return  p1.first * p2.second < p1.second * p2.first; 
}
class Solution {
public:
	vector<double> polars;
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
    	int sameCnt = 0, maxCnt = INT_MIN;
    	double polar;
    	for(auto point : points){
    		if(point[0] == location[0] and point[1] == location[1]);
    		int dx = point[0] - location[0];
    		int dy = point[1] - location[1];
    		polar = atan2(dy, dx);
    		polars.push_back(polar);
    	}
    	sort(polars.begin(), polars.end());
    	int len = polars.size();
    	for(int i = 0; i < len; i++){
    		polars.push_back(polars[i] + 2 * M_PI);
    	}
    	for(int i = 0; i < len; i++){
    		double curPolar = polars[i];
    		auto it = upper_bound(polars.begin() + i, polars.begin() + i + len, curPolar);
    		maxCnt = max(maxCnt, it - polars.begin() - i);
    	}
    	return maxCnt + sameCnt;


    	// sort(points.begin(), points.end());

    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}