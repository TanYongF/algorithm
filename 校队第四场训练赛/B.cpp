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
const int MAXN  = 1e5 + 10;
int T, len;
int num[MAXN];
ll dp[MAXN][501];
ll preAdd[MAXN];
int res ;
int main(int argc, char * argv[]){
	cin >> T;
	while(T--){
		cin >> len;
		res = 1;
		for(int i = 1 ; i <= len; i++) scanf("%d", &num[i]);
		for(int i =0 ; i <= len; i++) for(int j = 0; j <= 500; j++) dp[i][j] = 0;
		for(int i = len; i > 0; i--) preAdd[i] = num[i] +  preAdd[i + 1];
		dp[len][1] = num[len];
		for(int i = len-1; i > 0; i--) dp[i][1] = max(dp[i+1][1], 1LL * num[i]);
		for(int i = len - 1; i > 0; i--){
			for(int j = 2 ; j <= 500 and j <= (len - i); j++){
				dp[i][j] = dp[i+1][j];
				if(dp[i + j][j-1] != 0 and preAdd[i] - preAdd[i + j] < dp[i + j][j-1]){
					dp[i][j] = max(dp[i][j], preAdd[i] - preAdd[i + j]);
					res = max(res, j);
				}
			}
		}
		cout << res << endl; 
		/* code */

	}
    return 0;
}