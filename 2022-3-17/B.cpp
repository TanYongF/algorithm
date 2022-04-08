#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;

int T, m, n;
vector<vector<int>> g;
vector<pair<int,int>> ops;
int x[8] = {0, 0, -1, -1, -1, 1, 1, 1};
int y[8] = {1, -1, 1, 0, -1, 0, -1, 1};
set<pair<int,int>> pre, cur;
void move(pair<int,int> &p, int color, int k){
	int ci = p.first + x[k], cj = p.second + y[k], ei, ej;
	int flag = false;
	while(ci < n and cj < n and ci >= 0 and cj >= 0){
		if(g[ci][cj] == (not color)) ei=ci, ej=cj, flag = true;
		ci+=x[k], cj+=y[k];
	}
	if(not flag) return;
	ei-=x[k], ej-=y[k];
	while(ei != p.first or ej != p.second){
		if((not pre.count({ei,ej})) and g[ei][ej] != -1){
			// cout << ei << " " << ej << endl;
			cur.insert({ei, ej});
			g[ei][ej] = (not g[ei][ej]);
		}
		ei-=x[k], ej-=y[k];
	}
}
int main(int argc, char * argv[]){
	cin >> T;
	while(T--){
		ops.resize(0);
		cin >> n >> m;
		g = vector<vector<int>>(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++) for(int j = 0; j < n; j++){
			char cur;
			cin >> cur;
			if(cur == 'w') g[i][j] = 0;
			if(cur == 'b') g[i][j] = 1;
		}
		for(int i = 0; i < m; i++){
			int cx, cy;
			cin >> cx >> cy;
			ops.push_back({cx, cy});
		}
		int color = 0;
		for(int i = 0; i < ops.size(); i++){
			auto p = ops[i];
			cur = set<pair<int,int>>();
			for(int k = 0; k < 8; k++) move(p, color, k);
			g[p.first][p.second] = color;
			color = not color;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(g[i][j]==0) cout << 'w';
				else if(g[i][j]==1) cout << 'b';
				else cout << '-';
			}
			cout << endl;

		}
			pre = cur;
		}
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(g[i][j]==0) cout << 'w';
				else if(g[i][j]==1) cout << 'b';
				else cout << '-';
			}
			cout << endl;

		}
		cout << "END" << endl; 
	}
    return 0;
}

