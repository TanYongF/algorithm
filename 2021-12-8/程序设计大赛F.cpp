#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;
const int MAXN = 1e5+10;
int a[MAXN], b[MAXN];
int T, n, m;
void check(int val){
	
}
int main(int argc, char * argv[]){
	cin >> T;
	cin >> n >> m;
	for(unsigned i = 0; i < n; ++i) cin >> a[i];
	for(int i = 0 ; i < m; i++) cin >> b[i];
	sort(a, a+n);
	sort(b, b+m);
	int left = 0, right = INT_MAX, ans;
	while(left <= right){
		int mid = (left + right) >> 1;
		if(check(mid)){
			r = mid - 1;
			ans = mid;
		}else{
			l = mid + 1;
		}
	}
	cout << ans;
    return 0;
}