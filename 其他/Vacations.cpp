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
typedef unsigned long long ull;
#define ms(s) memset(s, 0, sizeof(s))
const int inf = 0x3f3f3f3f;
const int MAX = 105;
int dp[MAX][3];
int a[MAX];
int main(int argc, char * argv[]){
	ms(dp);
	int m;
	cin >> m;
	for(unsigned i = 0; i < m; ++i) {
		scanf("%d", a + i + 1);
	}
	for(unsigned i = 1; i <= m; ++i) {
		int minday = min(dp[i-1][0], dp[i-1][1]);
		minday = min(minday, dp[i-1][2]);
		if(a[i] == 0){
			dp[i][0] = minday + 1;
			dp[i][1] = minday + 1;
			dp[i][2] = minday + 1;
		}else if(a[i] == 1){
			dp[i][0] = minday + 1;
			dp[i][1] = min(dp[i-1][0], dp[i-1][2]);
			dp[i][2] = minday + 1;
		}else if(a[i] == 2){
			dp[i][0] = min(dp[i-1][1], dp[i-1][2]);
			dp[i][1] = minday + 1;
			dp[i][2] = minday+1; 
		}else{
			dp[i][0] = dp[i-1][1];
			dp[i][1] = dp[i-1][0];
			dp[i][2] = minday + 1;  
		}
	}
	int res = min(dp[m][0], dp[m][1]);
	cout << min(res, dp[m][2]);


    return 0;
}