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
#include <bitset>
#include <iostream>
#include <list>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;

class Solution {
public:
    int translateNum(int num) {
    	string str = to_string(num);	
    	const int len = str.size();
    	int dp[len+1];
    	memset(dp, 0, sizeof(dp)); 
    	dp[0] = 1;
    	dp[1] = 1;
    	for(int i = 2; i <= len; i++){
    		dp[i] = dp[i-1];
    		if(str[i-2] != '0' && (str[i-2]-'0')*10 + (str[i-1]-'0') <= 25) dp[i] += dp[i-2];
    	}
    	// for(int i = 1; i <= len; i++) cout << dp[i] << " ";
    	return dp[len];

    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	cout << s.translateNum(506);
	/* code */


    return 0;
}