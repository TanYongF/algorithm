#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;

int T;
const int MAXN = 40000;
int main(int argc, char * argv[]){
	int n, m;
	cin >> n >> m;
	vector<ll> nee(MAXN + 1, 0);
	vector<ll> old(MAXN + 1, 0);
	for(int i = 1; i <= m; i++) old[i] = 1;
	for(int i = 2; i <= n; i++){
		nee = vector<ll>(MAXN + 1, 0);
		for(int j = 1; j <= MAXN; j++){
			for(int k = 1; k + j <= MAXN and k <= m; k++){
				if(k != j) nee[j + k] += old[j];
			}
		}
		old = nee;
	}

	int ans = 0;
	for(int j = 1; j <= MAXN; j++){
		ans += nee[j];
	}
	cout << ans;

    return 0;
}