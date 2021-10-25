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
    bool isInterleave(string s1, string s2, string s3) {
		int l1 = s1.length(), l2 = s2.length(), l3 = s3.length();
    	s1.insert(s1.begin(),'0');
    	s2.insert(s2.begin(),'0');
    	s3.insert(s3.begin(),'0');
    	if(l3 != l1 + l2) return false;
    	bool dp[l3+1][l1+1];

    	for(int i = 0; i <= l3; ++i) 
    			memset(dp[i], false, sizeof(dp[i]));

    	for(int i = 0; i <= l1; ++i) 
    			dp[0][i] = true;

    	for(int i = 1; i <= l3; ++i) 
    		for(int j = 0; j <= min(i, l1); ++j) {
    				int k = i - j;

    				dp[i][j] = (j >= 1 && dp[i-1][j-1] && s1[j] == s3[i]) || (dp[i-1][j] && s2[k] == s3[i]);
    			}

    	for(int i = 0; i <= l3; ++i) {
    		for(int j = 0; j <= l1; ++j) cout << dp[i][j] << " ";	
    		cout << endl;	
    	}

    	return dp[l3][l1];
    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	cout << s.isInterleave("a","","a");
	/* code */


    return 0;
}