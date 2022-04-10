#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long MAXN = 501;
ll g[MAXN][MAXN];
int main(){
	long long N, M, K;
	memset(g, 0, sizeof(g));
	cin >> N >> M >> K;
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= M; j++){
			cin >> g[i][j];
			g[i][j] = g[i-1][j] + g[i][j-1] - g[i-1][j-1] + g[i][j]; 
			// cout << g[i][j] << " ";
		}
		// cout << endl;
	}
	int ans = 0;
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= M; j++){
			for(int oi = 1; oi <= i; oi++){
				for(int oj = 1; oj <= j; oj++){
					ll sum = g[i][j] - g[oi-1][j] - g[i][oj-1] + g[oi-1][oj-1];
					if(sum <= K) ans++; 
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}