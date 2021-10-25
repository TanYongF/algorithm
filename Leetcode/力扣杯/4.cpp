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
    int circleGame(vector<vector<int>>& toys, vector<vector<int>>& circles, int r) {
    	set<pair<int,int>> st;
    	for(auto circle : circles) st.insert({circle[0],circle[1]});
    	int ans = 0;
    	for(auto toy : toys){
    		bool ok = false;
    		int x = toy[0], y = toy[1], z = toy[2];
    		if(z > r) continue;
    		int k = r - z;
    		for(int dx = -k; dx <= k and not ok; dx++){
    			for(int dy = -k; dy <= k and not ok; dy++){
    				if(dx*dx + dy*dy > k*k) continue;
    				ok = st.count({x+dx, y+dy}); 
    			}
    		}
    		ans += ok;
    		
    	}
    	return ans;
    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}