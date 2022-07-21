#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int ans = 0;

const int MAXN = 2e5+10;
int main(){
	int m, n = 0;
	int ans = 0;
	cin >> n >> m;
	std::vector<int> a(MAXN, 0), b(MAXN, 0);
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) cin >> b[i];
	int l = 0, r = 5e5+10;
	auto check = [&](int val)->bool{
		int last = m;
		for(int i = 0; i < n; i++){
			int need = val - a[i];
			if(need > min(last, b[i])) return false;
			last -= need;
		}
		return true;
	};
	while(l <= r){
		int mid = (l + r) >> 1;
		if(check(mid)){
			ans = mid;
			l = mid + 1;
		}else r = mid - 1;
	}
	cout << ans;
	return 0;
}