#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;
const int MAXN = 1e4+10;
int g[MAXN][MAXN], dist[MAXN];
bool isCheck[MAXN];
int m, n, s;
void dijkstra(){
	for(int i = 1; i <= n; i++) dist[i] = g[s][i], isCheck[i] = false;
	dist[s] = 0, isCheck[s] = true;
	for(int i = 1; i <= n; i++){
		int nextId, nextValue = INT_MAX;
		for(int j = 1; j <= n; j++){
			if(not isCheck[j] and dist[j] < nextValue){
				nextId = j;
				nextValue = dist[j];
			}
		}
		isCheck[nextId] = true;
		for(int j = 1; j <= n; j++){
			if(g[nextId][j] != INT_MAX) dist[j] = min(dist[j], dist[nextId] + g[nextId][j]);
		}
	}
}
int main(int argc, char * argv[]){
	cin >> n >> m >> s;
	int x, y, z;
	for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) g[i][j] = INT_MAX;
	while(m--){
		cin >> x >> y >> z;
		g[x][y] = min(g[x][y], z);
	}
	dijkstra();
	for(int i = 1; i <= n; i++) cout << dist[i] << " ";
    return 0;
}
