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
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;

const int MAXN = 210;
class Solution {
public:
	
	long long dist[MAXN];
	bool vis[MAXN];
	vector<long long> f;
	vector<vector<long long>> g;
	long long mod = 1e9+7;
	void dijstra(vector<vector<long long>> &graph, int n){
		memset(vis, false, sizeof(vis));
		memset(dist, 0, sizeof(dist));
		vis[0] = 1;
		dist[0] = 0;
		for(int i = 1; i < n; i++) dist[i] = graph[0][i];
		int next = -1;
		for(int i = 1; i < n; i++){
			long long minDist = LLONG_MAX;
			for(int i = 1; i < n; i++){
				if(!vis[i] && dist[i] < minDist){
					next = i;
					minDist = dist[i];
				}
			}
			// cout << next << endl;
			vis[next]= true;
			for(int j = 1; j < n; j++)
				if(!vis[j] && dist[next] + graph[next][j] < dist[j]) 
					dist[j] = dist[next] + graph[next][j];
		}
	}
	long long dfs(int u, int n){
		if(u == n-1) return 1;
		if(f[u] != -1) return f[u];
		f[u] = 0;
		for(int v : g[u]){
			f[u] += dfs(v,n);
			if(f[u] >= mod) f[u] -= mod;
		}
		return f[u];

	}
    int countPaths(int n, vector<vector<int>>& roads) {
    	// int graph[n][n];
    	vector<vector<long long>> graph(n, vector<long long>(n, LLONG_MAX / 2));
    	//建图
    	for(auto road : roads){
    		int from = road[0];
    		int to = road[1];
    		int timeToUse = road[2];
    		graph[from][to] = timeToUse;
    		graph[to][from] = timeToUse;
    	}
    	dijstra(graph, n);
    	//DEBUG
    	// for(int i =0; i < n; i++) cout << dist[i] << " ";

    	//建立有向无环图g
    	g = vector<vector<long long>>(n);
    	for(auto&& road : roads){
    		int from = road[0], to = road[1], timeToUse = road[2];
    		if(dist[to] - dist[from] == timeToUse) g[from].push_back(to);
    		else if(dist[from] - dist[to] == timeToUse) g[to].push_back(from);
    	}

    	// for(auto vs : g){
    	// 	for(auto v : vs){
    	// 		cout << v << " ";
    	// 	}
    	// 	cout << endl;
    	// }

    	//记忆化搜索
    	f = vector<long long>(n, -1); //代表0 - 节点i的所有路径种类
    	return dfs(0, n);
    }
};



int main(int argc, char * argv[]){

	// Solution s = Solution();
	// vector<vector<int>> roads =  {{0,6,7},{0,1,2},{1,2,3},{1,3,3},{6,3,3},{3,5,1},{6,5,1},{2,5,1},{0,4,5},{4,6,2}};
	// cout << s.countPaths(7,roads);

	int b[10];
	ms(b, 10);
	cout << b[0];
	/* code */


    return 0;
}