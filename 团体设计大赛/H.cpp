#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define ms(s, val) memset(a, val, sizeof(a))

int main(){
	int n, k, s, a, b;
	std::vector<pair<int,int>> v(301, {0, 0});
	cin >> n >> k >> s;
	for(int i = 0; i < n; i++){
		cin >> a >> b;
		if(a < 175) continue;
		if(b >= s) v[a].second++;
		else v[a].first++;
	}
	int ans = 0;
	for(int i = 0; i < k; i++){
		for(int j = 175; j <= 300; j++){
			ans += (v[j].first == 0 ? 0 : 1) + v[j].second;
			v[j].second = 0;
			v[j].first = max(v[j].first-1, 0);
		}
	}
	cout << ans;
	return 0;
}