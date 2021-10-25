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
	int mod = 1e9+7;
	long long modAdd(long long a, long long b){
		return (a + b) % mod;
	}

    int checkRecord(int n) {
    	long long ans = 0;
    	long long dp[2][3];
    	memset(dp,0,sizeof(dp));
    	dp[0][0] = 1;
    	for(unsigned i = 1; i <= n; ++i) {
    		long long dpCur[2][3];
    		memset(dpCur, 0, sizeof(dpCur));
    		//情况'A'
    		for(unsigned j = 0; j < 3; ++j) 
    			dpCur[1][0] = modAdd(dpCur[1][0], dp[0][j]);

    		//情况'L'
    		for(unsigned j = 0; j < 2; ++j) 
				for(unsigned k = 1; k < 3; ++k) 
					dpCur[j][k] = modAdd(dp[j][k-1],dpCur[j][k]);
    		//情况'P'	
    		for(unsigned j = 0; j < 2; ++j) 
				for(unsigned k = 0; k < 3; ++k) 
					dpCur[j][0] = modAdd(dp[j][k],dpCur[j][0]);

			memcpy(dp, dpCur, sizeof(dp));
    	}
		for(unsigned j = 0; j < 2; ++j) 
			for(unsigned k = 0; k < 3; ++k) 
				ans = modAdd(dp[j][k],ans);

		return ans;
    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	cout << s.checkRecord(10101);
	/* code */


    return 0;
}