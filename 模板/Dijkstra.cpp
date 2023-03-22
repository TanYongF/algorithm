#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;
const int MAXN = 1e4+10;
int aa[100000000];
// int g[MAXN][MAXN],dist[MAXN];
// bool vis[MAXN];
// int n,m;
// void Dijkstra(){
// 	ms(vis, false);
// 	for(unsigned i = 1; i <= n; ++i) dist[i] = g[1][i]; 
// 	vis[1] = 1; //节点1加入到已经遍历的节点中来；
// 	dist[1] = 0;
// 	int next = INT_MAX;
// 	for(unsigned i = 2; i <= n; ++i) {
// 		int mini = INT_MAX;
// 		//找到距离最小并且没有遍历过的点
// 		for(unsigned i = 1; i <= n; ++i) {
// 			if(!vis[i] && dist[i] < mini){
// 				next = i;
// 				mini = dist[i];
// 			}
// 		}
// 		//这个点已经找到
// 		vis[next]= true;
// 		//更新经过这个点到达其他点的路径最小值
// 		for(unsigned j = 1; j <= n; ++j) {
// 			if(!vis[j] && dist[next]+g[next][j] < dist[j]){
// 				dist[j] = dist[next] + g[next][j];
// 			}
// 		}
// 	}
// }


// 堆存储的Kruskal算法
void dijstraHeap(){
	vector<vector<pair<int,int>>> g(MAXN);
	bool hasV[MAXN];
	int  dist[MAXN];
	int n, m, s, from, to, distance;
	cin >> n >> m >> s;
	ms(hasV, false);
	for(int i = 1; i <= n; i++) dist[i] = INT_MAX;
	priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> heap;
	while(m--){
		cin >> from >> to >> distance;
		g[from].push_back({to, distance});
	}
	dist[s] = 0;
	heap.push({0, s});

	while(heap.size()){
		auto [dis, node] = heap.top();
		heap.pop();

		//第一最短节点置位已遍历
		if(hasV[node]) continue;
		else hasV[node] = true;

		//遍历此节点往后的相邻节点,更新后续节点

	}		for(auto &[nextNode, nextDis] : g[node]){
			if(hasV[nextNode]) continue;
			if(dist[nextNode] > dis + nextDis){
				dist[nextNode] = dis + nextDis;
				heap.push({dist[nextNode], nextNode});
			}
		}
	for(int i = 1; i <= n; i++) cout << dist[i] << " ";
}
int main(int argc, char * argv[]){
	dijstraHeap();
    return 0;
}


// 最小生成树 Kruskal算法
struct Edge{
	int from, to, val;
	bool operator < (const Edge &w) const{
		return val < w.val;
	}
}
int find(int x){
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}

// m : 边数
// n : 节点数
int Kruskal(int m){
	 int res = 0;
	 for(int i = 0; i < n; i++) fa[i] = 0;
	 sort(edge, edge + m);
	for(int i = 0; i < m; i++){
		int a = edge[i].from, b = edge[i].to;
		if(find(a) != find(b)){
			res += edge[i].v;
			father[find(a)] = find(b);
		}
	}
	return s;
}