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
#define ms(s) memset(s, 0x3f3f3f3f, sizeof(s))
#define unsigned int 
const int inf = 0x3f3f3f3f;
const int MAX = 1005;	
int n, k;
int a[MAX];

int main(int argc, char * argv[]){
	cin >> n >> k;
	for(unsigned i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	for(unsigned i = 1; i < n; ++i) {
		a[i] -= a[0];
	}

	// cout << "--------" << endl;
	// for(unsigned i = 0; i < n; ++i) {
	// 	cout << a[i] << " ";
	// }

	int max = k * a[n-1];
	int dp[max+1];
	ms(dp);
	dp[0] = 0;
	for(unsigned i = 1; i < n; ++i) {
		for(unsigned j = a[i]; j <= max; ++j) {
			dp[j] = min(dp[j], dp[j - a[i]] + 1); 
		}
	}
	int n = k * a[0];
	// cout << "------------" << endl;
	// for(unsigned i = 0; i < max+1; ++i) {
	// 	cout << dp[i]<< " ";
	// }
	for(unsigned i = 0; i <= max; ++i) {
		if(dp[i] <= k) {
			printf("%d ",i + n);
		}
	}

    return 0;
}