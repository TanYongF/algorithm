#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <string>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <climits>
#include <vector>
#include <iostream>
#include <list>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;
class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
    	int n = grid[0].size();
    	long long pre[2][n];
    	pre[0][0] = grid[0][0], pre[1][0]  = grid[1][0];
    	for(int i = 0; i < 2; i++){
    		for(int j = 1; j < n; j++){
    			pre[i][j] = pre[i][j-1] + grid[i][j];
    		}
    	}
    	long long  ans = pre[0][n-1] - grid[0][0];
    	for(int  i = 1; i < n; i++){
    		long long cur= max(pre[0][n-1]- pre[0][i], pre[1][i-1]);
    		cout << cur << " ";
    		ans = min(cur, ans);
    	}
    	// for(int i = 1; i < n; i++){
    	// 	long long cur = pre[0][i] + (pre[1][n-1] - pre[1][i-1]);
    	// 	cout << cur << " " ;
    	// 	if(cur > maxD){

    	// 		maxD = cur;
    	// 		maxIdx = i;
    	// 	}
    	// }
    	// for(int i = 0; i <= maxIdx; i++) grid[0][i] = 0;
    	// for(int i = maxIdx; i < n; i++) grid[1][i] = 0;

    	// for(int i = 0; i < 2; i++){
    	// 	for(int j = 0; j < n; j++){
    	// 		cout << grid[i][j] << " "; 
    	// 	}
    	// 	cout << endl;
    	// }


    	// pre[0][0] = grid[0][0], pre[1][0]  = grid[1][0];

    	// for(int i = 0; i < 2; i++){
    	// 	for(int j = 1; j < n; j++){
    	// 		pre[i][j] = pre[i][j-1] + grid[i][j];
    	// 	}
    	// }
    	// maxD = pre[0][0] + pre[1][n-1];
    	// for(int i = 1; i < n; i++){
    	// 	long long cur = pre[0][i] + (pre[1][n-1] - pre[1][i-1]);
    	// 	if(cur > maxD){
    	// 		maxD = cur;
    	// 	}
    	// }
    	return ans;
    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	vector<vector<int>> t = 
{{1,3,1,15},{1,3,3,1}};
	cout << s.gridGame(t);
	/* code */


    return 0;
}