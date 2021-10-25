#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <string>
#include <cstring>
#include <algorithm>
#include <unordered_map>
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
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;
const int MAXN = 1010;
int T;
int mod =19260817;
ll dp[MAXN][MAXN];
int main(int argc, char * argv[]){
	int n, m;
	cin >> n >> m;
	dp[1][1] = 1;
	for(int i = 2; i <= n; i++){
		for(int j = 1; j <= i; j++){
			dp[i][j] = ((ll)j*dp[i-1][j]%mod+(ll)(i-j+1)*dp[i-1][j-1]%mod)%mod; 
		}
	}
	cout << dp[n][m+1];

    return 0;
}