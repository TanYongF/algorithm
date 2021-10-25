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
    int maxProfit(int k, vector<int>& prices) {
    	int len = prices.size(), times = min(len/2, k);
    	if(prices.size() == 0) return 0 ;
   
    	int buy[len][times+1],sell[len][times+1];
    	memset(buy, 0, sizeof(buy)); 
    	memset(sell, 0, sizeof(sell));
    	int ans = 0;
    	buy[0][0] = -prices[0];
    	sell[0][0] = 0;
 		for(int i = 1; i <= times; i++) buy[0][i] = sell[0][i] = INT_MIN/2;
    	for(int i = 1; i < len; i++){
    		buy[i][0] = max(buy[i-1][0], sell[i-1][0] - prices[i]);
    		for(int j = 1; j <= times; j++){
    			sell[i][j] = max(sell[i-1][j], buy[i-1][j-1]+prices[i]);
    			buy[i][j] = max(buy[i-1][j], sell[i-1][j]-prices[i]);
    		}
    	} 
    	for(int j = 0; j <= times; j++) ans = max(sell[len-1][j], ans);
    	return ans;
    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}