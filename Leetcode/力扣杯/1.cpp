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
    int minimumSwitchingTimes(vector<vector<int>>& source, vector<vector<int>>& target) {
    	int s1[10010], t1[10010];
        memset(s1, 0, sizeof(s1));
        memset(t1, 0, sizeof(t1));
    	for(int i = 0; i < source.size(); i++){
    		for(int j = 0; j < source[0].size(); j++){
    			s1[source[i][j]]++;
    			t1[source[i][j]]++;
    		}
    	}
    	long long ans = 0;
    	for(int i = 0; i < 10010; i++){
    		ans += abs(s1[i]-t1[i]);
    	}
    	return ans;
    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}