#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <string>
#include <cstring>
#include <algorithm>
#include <unordered_map>
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
typedef pair<int,int> P;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;

int T;
vector<vector<int>> g(50010);
int main(int argc, char * argv[]){
	int n ,x, y, from , to;
	cin >> n >> x >> y;
	for(int i = 1; i <= n-1; i++){
		cin >> from >> to;
		g[from].push_back(to);
		g[to].push_back(from);
	}
	for(auto it : g){
		for(auto v : it) cout << v << " ";
	}
	vector<int> xt(n+1);
	vector<int> xm(n+1);
	bool hasVisted[n+1];
	//美
	queue<pair<int,int>> q;
	q.push({x,0});
	hasVisted[x] = true;
	while(!q.empty()){
		P curnode = q.front();
		q.pop();
		for(auto next : g[curnode.first]){
			if(!hasVisted[next]){
				xm[next] = curnode.second+1;
				q.push({next,curnode.second+1});
			}
			hasVisted[next] = true;
		}
	}
	//团	
	ms(hasVisted, false);		
	q.push({y,0});
	hasVisted[y] = true;
	while(!q.empty()){
		P curnode = q.front();
		q.pop();
		for(auto next : g[curnode.first]){
			if(!hasVisted[next]){
				xt[next] = curnode.second+1;
				q.push({next,curnode.second+1});
			}
			hasVisted[next] = true;
		}
	}
	int ans = INT_MIN;
	// for(auto it : xm) cout << it << " " ;
	for(int i = 1; i <= n; i++)	if(xt[i] < xm[i]) ans = max(ans, xm[i]);
	cout << ans;
    return 0;
}