#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <string>
#include <cstring>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <ctime>
#include <climits>
#include <vector>
#include <iostream>
#include <fstream>
#include <list>
#include <iomanip>
#include <numeric>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = 1e5+10;
int n,queries;
std::vector<std::vector<int>> G(inf);
queue<int> q;
vector<int> t(inf);
bool hasVisted[inf];
int ans = 0;
void slove(int start, int tL, int tR){
	if(t[start] >= tL && t[start] <= tR) q.push(start);
	hasVisted[start] = true;
	while(!q.empty()){
		int from = q.front();
		for(auto next : G[from]){
			if(hasVisted[next]) continue;
			if(t[next] >= tL && t[next] <= tR){
				q.push(next);
				hasVisted[next] = true;
			}
		}
		q.pop();
		ans++;
	}
}
int main(int argc, char * argv[]){
	cin >> n;
	int u,v;
	for(unsigned i = 0; i < n-1; ++i) {
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i = 1; i <= n; i++) cin >> t[i];
	cin >> queries;
	int tL, tR, start;
	while(queries--){
		ans = 0;
		ms(hasVisted,false);
		cin >> start >> tL >> tR;
		slove(start, tL, tR);
		cout << ans << endl;
	}
    return 0;
}