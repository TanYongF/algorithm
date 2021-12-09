//http://8.130.166.109/problem/G
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;
const int MAXN = 1e5+10;
int T, n;
int a[MAXN];
int main(int argc, char * argv[]){
	cin >> T;
	while(T--){
		cin >> n;
		for(int i = 1; i <= n; i++) cin >> a[i];
		sort(a+1, a+1+n, greater<int>());
		int add = 1, adds = 1;
		while(add < n and a[add + 1] >= add + 1) add++;
		while(a[adds+1]>=add) adds++;
		int ans = ((a[add] - add)&1) || ((adds-add)&1);
		puts(ans ? "Black" : "White");
		/* code */
	}
	return 0;

	


    return 0;
}