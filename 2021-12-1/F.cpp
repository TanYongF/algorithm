#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;
const int MAXN = 2e5+10;
bool ok = false;
int T, day, a[MAXN], b[MAXN], n, c;
int main(int argc, char * argv[]){
	cin >> T;
	while(T--){
		vector<ll> odp(MAXN, -1), ndp(MAXN, -1);
		ok = false;
		cin >> n >> c;
		for(int i = 1; i <= n; i++) cin >> a[i];
		for(int i = 1; i <  n; i++) cin >> b[i];
		odp[1] = a[1];
		int ans = INT_MAX;
		day = 1;
		if(odp[1] >= c) { cout << 1 << endl; continue;}
		while(true){
			day++;
			for(int i = 1; i <= n; i++){
				if(odp[i] != -1) ndp[i] = odp[i] + a[i];
				if(i >= 1){
					if(odp[i-1] >= b[i-1]) ndp[i] = max(ndp[i], odp[i-1] - b[i-1]);
				}
				if(ndp[i] >= c){
					ok = true;
					break;
				}
				ans = min(ans, (int)ceil(1.0 * (c - ndp[i]) / a[i]));
				if(ndp[n] > -1) break;
			}
			if(ndp[n] > -1){
				cout << day + ans << endl;
				break;
			}
			if(ok){
				cout <<  day << endl;
				break;
			}
			odp = ndp;
		}
	}
    return 0;
}