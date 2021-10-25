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
#include <vector>
#include <fstream>
#include <list>
#include <iomanip>
#include <numeric>
using namespace std;
typedef long long ll;
#define unsigned int
typedef unsigned long long ull;
#define ms(s) memset(s, 0, sizeof(s))
const int inf = 0x3f3f3f3f;
const int MAX = 100005;
ll dp[MAX][9];
int mod = 1e9+7;

int main(int argc, char * argv[]){
	char s[10005];
	char pattern[9] = {' ','c','h','o','k','u','d','a','i'};
	scanf("%s", s+1);
	cin >> (s+1);
	cout << strlen(s+1);
	for(unsigned i = 0; i < MAX; ++i) {
		ms(dp[i]);
		dp[i][0] =1;
	}
	// /* code */
	
	for(unsigned i = 1; i <= strlen(s+1); ++i) {
		for(unsigned j = 1; j <= 8; ++j) {
			if(s[i] != pattern[j]) {
				dp[i][j] = dp[i-1][j];
			}else{
				dp[i][j] = (dp[i-1][j] + dp[i-1][j-1]) % mod;
			}
		}                           
	}
	// for(unsigned i = 1; i <= strlen(s+1); ++i) {
	// 	for(unsigned j = 1; j < 9; ++j) {
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << " " << endl;
	// }
	// cout << mod << endl;
	cout << dp[strlen(s+1)][8] << endl;
   
}