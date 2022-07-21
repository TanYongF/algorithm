#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii; 
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;
const int MAXN = 1e3 + 10;
int T;
int main(int argc, char * argv[]){
	int N, M;
	cin >> N >> M;
	std::vector<int> dist(MAXN, INT_MAX);
	vector<vector<pair<int,int>>> g(MAXN);
	vector<int> wait(MAXN, 0);
	for(int i = 1; i <= N; i++) cin >> wait[i];
	while(M--){
		int from, to, value;
		cin >> from >> to >> value;
		g[from].push_back({to, value});
	}
	priority_queue<pii,vector<pii>, greater<pii>> heap;

	dist[1] = 0;
	heap.push({0, 1});
	while(not heap.empty()){
		auto [curDis, curNode] = heap.top();
		heap.pop();

		if(curDis > dist[curNode]) continue;
		dist[curNode] = curDis;
		for(auto &[nextNode, val] : g[curNode]){
			int nextDis = curDis + val + wait[nextNode];
			heap.push({nextDis, nextNode});
		}
	}
	for(int i = 1; i <= N; i++) cout << dist[i] <<  " ";
	cout << dist[N] - wait[N];
    return 0;
}