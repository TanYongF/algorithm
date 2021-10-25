//https://leetcode-cn.com/problems/edit-distance/
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
    int minDistance(string word1, string word2) {
    	int len1= word1.length(), len2 = word2.length();
    	int dp[len1+1][len2+1];
    	memset(dp, 0, sizeof(dp));
    	for(int i = 0; i <= len1; i++) dp[i][0] = i;
    	for(int j = 0; j <= len2; j++) dp[0][j] = j;
    	for(int i = 1; i <= len1; i++){
    		for(int j = 1; j <= len2; j++){
    			if(word1[i-1] == word2[j-1]) dp[i][j] = dp[i-1][j-1];
    			else dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1])+1;
    		}
    	}
    	return dp[len1][len2];

    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}