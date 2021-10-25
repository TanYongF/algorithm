//https://leetcode-cn.com/problems/non-negative-integers-without-consecutive-ones/
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
    int findIntegers(int n) {
    	pair<int,int> dp[28][2];
    	dp[1][0] = {0,1};
    	dp[1][1] = {1,1};
    	for(int i = 2; i <= 28; i++){

    	}
        

    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}