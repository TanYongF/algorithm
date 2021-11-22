#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 10;
int m, a[MAXN], minn[MAXN], maxx[MAXN]; 
int main(int argc, char const *argv[]){
	cin >> m;
	for(int i = 1; i <= m; i++)	{
		cin >> a[i];
	}
	maxx[0] = INT_MIN, minn[m+1] = INT_MAX;
	int ans = -1;
	for(int i = m; i >= 1; i--) minn[i] = min(minn[i+1], a[i]);
	for(int i = 1; i <= m; i++) maxx[i] = max(maxx[i-1], a[i]);
	for(int i = 0; i <= m; i++)
		if(maxx[i] <= minn[i]) ans++;
	cout << ans;
	return 0;
}