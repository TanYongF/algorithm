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
    int maxProfit(vector<int>& prices) {
    	int buy1 = 0, buy2 = 0, sell1 = 0, sell2 = 0;
    	buy1 = -prices[0];
    	buy2 = -prices[0];
    	for(int i = 1; i < prices.size(); i++){
    		buy1 = max(buy1, - prices[i]); // 继续保持上一个状态或者是买入
    		sell1 = max(sell1, buy1 + prices[i]);	//继续保持上一个状态, 并且买入 
    		buy2 = max(buy2, sell1-prices[i]);
    		sell2 = max(sell2, buy2 + prices[i]);
    		// cout << buy1 << " " << sell1 << " " << buy2 << " " << sell2 << endl;
    	}
    	return sell2;


    }
};

int main(int argc, char * argv[]){
	vector<int> test = {3,3,5,0,0,3,1,4};
	Solution s = Solution();
	cout << s.maxProfit(test);
	/* code */



    return 0;
}