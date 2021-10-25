//https://leetcode-cn.com/problems/delete-operation-for-two-strings/
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
    	int len1 =word1.length(), len2 = word2.length();
    	int dp[len1+1][len2+1];
    	memset(dp, 0, sizeof(dp));
    	for(int i = 1; i <= len1; i++){
    		for(int j = 1; j <= len2; j++){
    			dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    			if(word1[i-1] == word2[j-1]) dp[i][j] = max(dp[i][j], dp[i-1][j-1]+1);
    		}
    	}
    	return len1+len2-2*dp[len1][len2];
        

    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}