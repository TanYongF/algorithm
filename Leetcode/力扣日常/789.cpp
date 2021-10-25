#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <string>
#include <cstring>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <ctime>
#include <climits>
#include <vector>
#include <iostream>
#include <fstream>
#include <list>
#include <iomanip>
#include <numeric>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;

class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int minxx = INT_MAX, maxxx = INT_MIN, minyy = INT_MAX, maxyy = INT_MIN;
        int minD = INT_MAX;
        for(ghost : ghosts){
        	minD = min(minD, abs(target[0] - ghost[0]) + abs(target[1] - ghost[1]))
        }
       	if(minD >= target[1] + target[0]) return true;
       	return false;
    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}