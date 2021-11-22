#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1005;
int m, n;
int a[MAXN];
bool cmp(int a, int b) {
	return a > b; 
}
int main(){
	cin >> m >> n;
	for(int i =0 ; i < m; i++){
		cin >> a[i];
	}
	sort(a, a + m, cmp);
	long long ans = 0;
	for(unsigned i = 0; i < n; ++i) {
		ans += a[i];
	}
	cout << ans; 
}