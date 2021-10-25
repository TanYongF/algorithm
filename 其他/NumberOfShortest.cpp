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
#include <vector>
#include <fstream>
#include <list>
#include <iomanip>
#include <numeric>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s) memset(s, 0, sizeof(s))
const int inf = 0x3f3f3f3f;
const int MAX  = 200005;
std::vector<int> v[MAX];
ll res, N , M;
int nodeCnt = MAX;

int step[200005]; // step[i]表示到第i个节点的步数
int pathNum[200005]; // pathNum[i]表示到第i个节点的最短路径条数
int calculatePathNum(std::vector<int> graph[]) {
    memset(step, 0, sizeof(int)*nodeCnt);
    memset(pathNum, 0, sizeof(int)*nodeCnt);
    pathNum[1] = 1; // 起点到起点的路径数量为1
    std::queue<int> q; // 广度优先搜索中保存当前到达的节点
    q.push(1); // 首先到达起点
    int from, i, s;
    while (!q.empty()) {
        from = q.front();
        q.pop();
        s = step[from] + 1; // 和from节点相邻的节点的路径长度
        for (i = 2; i <= N; i++) { // 0是起点，不需要遍历
            if (std::find(graph[from].begin(), graph[from].end(), i) != graph[from].end()) { // 从from到i是连通的
            	// cout << "      " << endl;
                if (step[i] == 0 || step[i] > s) { // i节点从未到达过或发现更快的路径
                    step[i] = s;
                    pathNum[i] = pathNum[from];
                    q.push(i); // 将和from相邻的节点入队，相当于广度优先搜索中form节点的下一层节点入队
                } else if(s == step[i]){ // 发现相同长度的路径
                    pathNum[i] += pathNum[from];
                }
            }
        } 
    }
    return pathNum[N];
}

int main(int argc, char * argv[]){
	cin >> N >> M;
	int from, to;
	for(unsigned i = 0; i < M; ++i) {
		// cin >> from >> to;
		scanf("%d %d", &from, &to);
		v[from].push_back(to); 
		v[to].push_back(from);
	}
	// cout << "" << endl;
	// for(unsigned i = 1; i <= N; ++i) {
	// 	for(unsigned j = 0; j < v[i].size(); ++j) {
	// 		cout << v[i][j] << " " ;
	// 	}
	// 	cout << "   " << endl;
	// }
	cout << calculatePathNum(v);


	/* code */


    return 0;
}