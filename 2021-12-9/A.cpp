#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;
const int MAXN = 205;
int T,maxDis,u;
typedef pair<int,int> P;
std::vector<P> v;
vector<bool> has(MAXN);
vector<unordered_set<int>> g(MAXN);
vector<int> f;
int m,from,to;
int ans = INT_MIN;
void dfs(int curnode,int dis){
	if(dis > maxDis){
		u = curnode;
		maxDis = dis;
	}
	has[curnode] = true;
	for(auto next : g[curnode]){
		if(not has[next]) dfs(next,dis + 1);
	}
	return;
}
int getL(int curnode){
	maxDis = -1;
	has = vector<bool>(m+1,false);
	dfs(curnode,0);
	maxDis = -1;
	has = vector<bool>(m+1,false);
	dfs(u,0);
	return maxDis;
}

int main(){
	cin >> m;
	for(int i = 0; i < m-1; i++){
		cin >> from >> to;
		v.push_back(make_pair(from,to));
		g[from].insert(to);
		g[to].insert(from);
	}
	for(P del : v){
		auto df = g[del.first].find(del.second), dt = g[del.second].find(del.first);
		g[del.first].erase(df);
		g[del.second].erase(dt);
		ans = max(ans,getL(del.first) * getL(del.second));
		g[del.first].insert(del.second);
		g[del.second].insert(del.first);
	}
	cout << ans << endl;
	return 0;
}
