#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;

int T, n;
vector<int> v;
unordered_map<int,int> fa;
vector<vector<int>> g;
unordered_map<int, int> mp;
int dfs(vector<vector<int>> &g, int root){

	if(g[root].size() == 0){
		return mp[root] = v[root];
	}
	int cur = v[root];
	if(g[root].size() >= 1) cur += dfs(g, g[root][0]);
	if(g[root].size() >= 2) cur += dfs(g, g[root][1]);
	return mp[root] = cur; 
}

void dfs2(vector<vector<int>> &g, int root){
	if(g[root].size() == 0){
		return;
	}
	if(g[root].size() >= 1){
		fa[g[root][0]] = root;
		dfs2(g, g[root][0]);
	}
	if(g[root].size() >= 2){
		fa[g[root][1]] = root;
		dfs2(g, g[root][1]);
	}
}

bool check(int a, int b){
	unordered_set<int> st1, st2;
	int lasta = a, lastb=  b;
	st1.insert(a);
	st2.insert(b);
	while(fa[a] != -1){
		st1.insert(fa[a]);
		a = fa[a];
	}
	while(fa[b] != -1){
		st2.insert(fa[b]);
		b = fa[b];
	}
	return (st1.count(lastb) == 0 and st2.count(lasta) == 0);
}
int temp;
int main(){
	fa[0] = -1;
	cin >> n;
	g = vector<vector<int>>(n);
	for(int i = 0; i < n; i++){
		cin >> temp;
		v.push_back(temp);
	}
	int ans = INT_MAX;
	int from, to;
	for(int i = 0; i < n-1; i++){
		cin >> from >> to;
		g[from-1].push_back(to-1);
	}
	dfs(g, 0);
	dfs2(g, 0);
	for(int i = 0 ; i < n; i++){
		for(int j = 0; j < n; j++){
			bool flag = check(i, j);
			if(flag){
				ans = min(ans, abs(mp[i]-mp[j]));
			} 
		}
	}
	if(ans == INT_MAX) cout << 1000000000;
	else cout << ans;
    return 0;
}
