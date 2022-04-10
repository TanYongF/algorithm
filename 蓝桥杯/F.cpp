#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long MAXN = 5e4+10;
vector<vector<int>> d;
vector<vector<int>> h;
int fa[MAXN];
int getfa(int val){
	if(val != fa[val]) fa[val] = getfa(fa[val]); 
	return fa[val];
}
void merge(int val1, int val2){
	int fa1 = getfa(val1), fa2 = getfa(val2);
	fa[fa1] = fa2;
}
int main(){
	int n, m, x, y, r;
	cin >> n >> m;
	unordered_map<int,int> mp;
	d.clear();
	h.clear();
	for(int i = 0; i < n; i++) fa[i] = i;
	for(int i = 0; i < n; i++){
		cin >> x >> y >> r;
		d.push_back(vector<int>({x, y, r})); 
	}
	for(int i = 0; i < m; i++){
		cin >> x >> y >> r;
		h.push_back(vector<int>({x, y, r})); 
	}
	for(int i = 0; i < n; i++){
		ll x1 = d[i][0], y1 = d[i][1], r1 = d[i][2];
		for(int j = 0; j <= i; j++){
			ll x2 = d[i][0], y2 = d[i][1], r2 = d[i][2];
			if((x1-x2)*(x1-x2) + (y1-y2) * (y1-y2) <= (r1 + r2)*(r1+r2)) merge(i, j);
		}
	}
	for(int i = 0; i < n; i++){
		mp[getfa(i)]++;
	}

	int ans = 0;
	for(int i = 0; i < m; i++){
		ll x1 = h[i][0], y1 = h[i][1], r1 = h[i][2]; 
		for(int j = 0; j < n; j++){
			int father = getfa(j);
			ll x2 = d[i][0], y2 = d[i][1], r2 = d[i][2];
			if(not mp.count(father)) continue;
			if((x1-x2)*(x1-x2) + (y1-y2) * (y1-y2) <= (r1 + r2)*(r1+r2)){
				ans += mp[father];
				mp.erase(father);
			}
		}
	}
	cout << ans;
	return 0;
		
}