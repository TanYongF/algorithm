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
int n = 0;
const int MAX = 100005;
int nums[MAX];

int main(int argc, char * argv[]){
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> nums[i];
	}
	int res = 1;
	int dp[n+1];
	ms(dp);
	dp[0] = 1;
	for(int  i = 1; i < n; ++i) {
		dp[i] = nums[i] >= nums[i-1] ? (dp[i-1]+1) : 1;
		// cout << dp[i] << endl;
		res = max(dp[i], res);  
	}
	cout << res;
    return 0;
}