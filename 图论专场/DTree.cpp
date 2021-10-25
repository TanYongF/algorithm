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
const int inf = INT_MAX;
int n, u ,v;
const int MAXN =  1e5 + 10;
int color[MAXN];
int LS ,RS;
std::vector<vector<int>> G(MAXN);
void dfs(int curNode, int curColor){
	int nextColor = curColor == 1 ? 2 : 1;
	for(auto node : G[curNode]){
		if(color[node]) continue;
		color[node] = curColor;
		dfs(node, nextColor);
	}
}
int main(int argc, char * argv[]){
	cin >> n;
	for(unsigned i = 1; i <= n-1; ++i) {
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	color[1] = 1;
	dfs(1, 2);
	for(int i = 1; i <= n ;i++){
		if(color[i] == 1) LS++;
		else 			  RS++;
	}
	ll ans = 1.L * LS * RS - n + 1;
	cout << ans ; 
    return 0;
}