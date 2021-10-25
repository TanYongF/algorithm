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
typedef pair<int,int> P;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;
const int MAXN = 2e5+10;
int m, n, T, from, to, type;

vector<P> ungrap;
std::vector<int> grap[MAXN];
int indgree[MAXN];
vector<int> topo;
queue<int> q;
unordered_map<int,int> mp(MAXN);
void init(){
	for(unsigned i = 0; i <= m; ++i) {
		grap[i].clear();
	}
	ungrap.clear();
	ms(indgree,0);
	topo = vector<int>();
	q = queue<int>();
	mp= unordered_map<int,int>(MAXN);

}
int main(int argc, char * argv[]){
	cin >> T;
	// cout << T << endl;
	while(T--){
		// cin >> m >> n;
		scanf("%d %d", &m, &n);
		// cout << "---------" << m << " " << n << endl;
		// cout << q.size() << mp.size() << indgree.size() << grap[0].size() << endl ;
		init();
		for(unsigned i = 1; i <= n; ++i) {
			// cin >> type >> from >> to ;
			scanf("%d %d %d", &type, &from, &to);
			if(type==1) grap[from].push_back(to), indgree[to]++;
			else{
				P unEdge = P(from,to);
				ungrap.push_back(unEdge);
			}
		}


		//gettopo
		for(unsigned i = 1; i <= m; ++i)  if(indgree[i] == 0) q.push(i);
				// for(unsigned i = 1; i <= m; ++i) cout << indgree[i]  << " " ;
				// 	cout << endl;
		while(!q.empty()){
			int curnode = q.front();
			topo.push_back(curnode);
			mp[curnode] = topo.size();
			q.pop();
			for(unsigned i = 0; i < grap[curnode].size(); ++i){
				indgree[grap[curnode][i]]--;
				if(indgree[grap[curnode][i]] == 0){
					// topo.push_back(grap[curnode][i]);
					q.push(grap[curnode][i]);
				}
			}
		} 

		if(topo.size() < m){
			cout << "NO" << endl;
			continue;
		}
		//映射成<元素，拓扑顺序
		cout << "YES" << endl;

					// 	for(unsigned i = 0; i < m; ++i) cout << topo[i]  << " " ;
					// cout << endl;


		for(auto edge :  ungrap){
			from = edge.first;
			
			to   = edge.second;
			if(mp[from] < mp[to]) printf("%d %d\n",from, to );
			else printf("%d %d\n",to, from);
		}
		for(unsigned i = 1; i <= m; ++i) 
			for(auto next : grap[i])
				printf("%d %d\n",i, next);
	}
    return 0;
}