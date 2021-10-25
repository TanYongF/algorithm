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
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    	vector<vector<int>> dp(n+1, vector<int>(k+2,1e6));
    	dp[src][0] = 0;
    	for(int i =1; i <= k+1; i++){
    		for(auto flight : flights){
    			dp[flight[1]][i] = min(dp[flight[0]][i-1]+flight[2], dp[flight[1]][i]); 
    		}
    	}
    	int ans = INT_MAX;
    	for(int i = 0; i <= k+1; i++){
    		ans = min(ans, dp[dst][i]); 
    	}
    	return ans;
    }
};
int main(int argc, char * argv[]){
	// int a[100];
	// memset(a, 100, sizeof(a));
	// for(int i = 0 ; i< 100;i++) cout << a[i]<<endl;

	Solution s = Solution();
	vector<vector<int>> flights={{1,2,10},{2,0,7},{1,3,8},{4,0,10},{3,4,2},{4,2,10},{0,3,3},{3,1,6},{2,4,5}};
	cout << s.findCheapestPrice(5,flights,0,4 ,1);


    return 0;
}