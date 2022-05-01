#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define ms(s, val) memset(a, val, sizeof(a))

const int MAXN = 2e6+10;
vector<vector<int>> g(MAXN);
bool hav[MAXN];
vector<vector<int>> ans;
// vector<int> temp;
void dfs(int cur, vector<int> temp){
	if(g[cur].size() == 0){
		ans.push_back(temp);
	}

}
int main(){
	int a, b, n, r;
	cin >> n >> r;
	ms(hav,0);
	while(cin >> a >> b){
		g[a].push_back(b);
		// g[m].push_back(b);
	}
	dfs(g);
}