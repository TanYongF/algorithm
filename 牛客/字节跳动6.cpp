#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <string>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <climits>
#include <vector>
#include <iostream>
#include <list>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;
const int INF = 5050;
struct Edge{
	int from, to, val;
};
int N,M;
ll result =0;

vector<int> father(INF);
int findset(int x){
	if(x != father[x]) father[x] = findset(father[x]);
	return father[x];
}
void unionset(int a, int b){
	int x = findset(a);
	int y = findset(b);
	if(x!=y){
		father[y] = x;
	}
}
int cmp(Edge e1, Edge e2){
	return e1.val < e2.val;
}

int main(int argc, char * argv[]){
	cin >> N >> M;
	vector<Edge> edges(M);
	int curIdx = 0, nEdge = 0;
	for(int i = 0; i < INF; i++) father[i] = i;
	for(int i = 0; i < M; i++) cin >> edges[i].from >> edges[i].to >> edges[i].val;
	sort(edges.begin(), edges.end(), cmp);

	for(auto edge : edges){
		if(nEdge == N-1) break;
		if(findset(edge.from) != findset(edge.to)){
			unionset(edge.from, edge.to);
			result += edge.val;
			nEdge++;
		}
	}
	if(nEdge < N-1) cout << "不是一个连通图" << endl;
	else cout << result <<endl;
	return 0;
}