#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define ms(s, val) memset(a, val, sizeof(a))
int main(){
	int n, m, q, t, idx;
	cin >> n >> m >> q;
	set<int> row, col;
	for(int i = 0; i < q; i++){
		cin >> t >> idx;
		if(t==0) row.insert(idx);
		else col.insert(idx);
	}
	int ans = 0;
	for(unsigned i = 1; i <= n; ++i) {
		if(row.count(i)) continue;
		for(unsigned j = 1; j <= m; ++j) {
			if(col.count(j) == 0) ans++;
		}
	}
	cout << ans;

	return 0;
}