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
const int MAXN = 1e4;
int g[MAXN][MAXN],dist[MAXN];
bool vis[MAXN];
int n,m;
void Dijkstra(){
	ms(vis, false);
	for(unsigned i = 1; i <= n; ++i) dist[i] = g[1][i]; 
	vis[1] = 1; //节点1加入到已经遍历的节点中来；
	dist[1] = 0;
	int next = INT_MAX;
	for(unsigned i = 2; i <= n; ++i) {
		int mini = INT_MAX;
		//找到距离最小并且没有遍历过的点
		for(unsigned i = 1; i <= n; ++i) {
			if(!vis[i] && dist[i] < mini){
				next = i;
				mini = dist[i];
			}
		}
		//这个点已经找到
		vis[next]= true;
		//更新经过这个点到达其他点的路径最小值
		for(unsigned j = 1; j <= n; ++j) {
			if(!vis[j] && dist[next]+g[next][j] < dist[j]){
				dist[j] = dist[next] + g[next][j];
			}
		}
	}
}
int main(int argc, char * argv[]){
	cin >> n;

	/* code */


    return 0;
}