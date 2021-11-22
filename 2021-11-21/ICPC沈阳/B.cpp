#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;
const int MAXN = 1e5 + 10;
typedef  pair<int,int> P;
int n, m, sum, s;
vector<int> color(MAXN);
vector<vector<P>> G(MAXN);
int u[MAXN], v[MAXN], w[MAXN];

void dfs(int x, int c){
	// cout << x << " " << c;
	color[x] = c;
	sum++;
	if(c) s++;
	for(int i = 0; i < (int)G[x].size(); i++){
		int ne = G[x][i].first, nc = G[x][i].second;
		if(color[ne] == -1){
			dfs(ne, c ^ nc);
		}else{
			if(color[ne] != (c^nc)){
				cout << -1;
				exit(0);
			}
		}
	}
}

long long ans =0 ;
int main(int argc, char * argv[]){
	cin >> n >> m;
	for(int i = 1; i <= m; i++) cin >> u[i] >> v[i] >> w[i]; 
	for(int k = 0; k < 30; k++){
		for(int i = 0; i <= n; i++) color[i] = -1, G[i].clear();
		for(int i = 1; i <= m; i++){
			G[u[i]].push_back(make_pair(v[i], w[i] >> k & 1));
			G[v[i]].push_back(make_pair(u[i], w[i] >> k & 1));
		}
		for(int i = 1; i <= n; i++){
			if(color[i] != -1) continue;
			sum = 0, s = 0;
			dfs(i, 0);
			cout << sum << s << endl;
			ans += 1LL * min(s, sum-s) * (1 << k);
		}
	}
	cout << ans;
    return 0;
}