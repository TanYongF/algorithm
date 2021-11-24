#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;
const int MAXN = 1e4 + 10;
int T,x,y,n,m,c;
int fa[MAXN];
int dp[505];
vector<P> p(MAXN);
int find(int val){
	if(fa[val] != val) fa[val] = find(fa[val]);
	return fa[val];
}
void unionset(int x, int y){
	if(x > y) swap(x, y);
	fa[find(y)] = find(x);
}
int main(int argc, char * argv[]){
	cin >> T;
	while(T--){
		memset(dp,0,sizeof(dp));
		cin >> n >> m >> c;
		for(int i = 1; i <= n; i++) fa[i] = i;
		for(int i = 1; i <= n-1; i++){
			cin >> x >> y;
			p[i+1] = {x, y};
		}
		for(int i = 0; i < m; i++){
			cin >> x >> y;
			unionset(x, y);
		}
		// for(int i = 2; i <= n; i++) cout << fa[i] << " ";
		for(int i = 2; i <= n; i++){
			if(find(i) != 1) continue;
			for(int j = c; j >= p[i].first; j--){
				dp[j] = max(dp[j],dp[j-p[i].first] + p[i].second);
			}
		}
		cout << dp[c] << endl;
	}

    return 0;
}