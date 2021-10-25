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
    int maximalSquare(vector<vector<char>>& matrix) {
    	int row = matrix.size();
    	int col = matrix[0].size();
    	int dp[row][col];
    	for(int i = 0; i< row;i++) memset(dp[i], INT_MAX, sizeof(dp[i]));
    	int res=  0;
    	for(int i = 0; i < col; i++) {
    		if(matrix[0][i] == '1'){
    			dp[0][i] = 1;
    			res = 1;
    		}else{
    			dp[0][i] = 0;
    		}
    	} 
		for(int i = 0; i < row; i++) {
    		if(matrix[i][0] == '1'){
    			dp[i][0] = 1;
    			res = 1;
    		}else{
    			dp[i][0] = 0;
    		}
		}
    	for(int i = 1; i < row; ++i) {
    		for (int j = 1; j < col; ++j){
    			if(matrix[i][j] == '0') {dp[i][j] = 0; continue;}
    			dp[i][j] = min(dp[i-1][j], dp[i-1][j-1]);
    			dp[i][j] = min(dp[i][j], dp[i][j-1]) + 1;	
    			res = max(res, dp[i][j]);
    		}
    	}
    	return res * res;
    }
};


int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}