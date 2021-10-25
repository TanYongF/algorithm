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
#define ms(s, num) memset(s, num, sizeof(s))
const int inf = 0x3f3f3f3f;
const int MAX = 200005;
const int MOD = 1e9+7;
int N, M;
std::vector<int> grap[MAX];
std::queue<int>  q;
ll cnt[200005];
ll  dist[200005];
int main(int argc, char * argv[]){
	cin >> N >> M;
	ms(cnt, 0);
	ms(dist,-1);
	/* code */
	int from, to;
	for(unsigned i = 0; i < M; ++i) {
		scanf("%d %d", &from, &to);
		grap[from].push_back(to);
		grap[to].push_back(from);
	}
	cnt[1] = 1;
	dist[1] = 0;
	int curNode;
	q.push(1);
	//使用BFS遍历
	while(!q.empty()){
		curNode = q.front();
		q.pop();
		//遍历当前节点
		for(unsigned i = 0; i < grap[curNode].size(); ++i) {
			int nextNode = grap[curNode][i];
			//如果此节点没有遍历过，那么使其距离是 上一节点的距离加1， 到达此节点的方法是上一节点的方法次数 并吧当前节点加入到queue中
			if(dist[nextNode] == -1){
				dist[nextNode] = dist[curNode] + 1;
				q.push(nextNode);
				cnt[nextNode] = cnt[curNode];
			//如果遍历过，并且是当前的最短路径的话
			}else if(dist[curNode] + 1 == dist[nextNode]){
				//如果此节点已经遍历过，那么使其方法
				cnt[nextNode] = (cnt[nextNode] + cnt[curNode]) % MOD;
			}else{
				dist[nextNode] = min(dist[nextNode], dist[curNode] + 1);
				cnt[nextNode]  = cnt[curNode];
			}
			
		}
	}
	cout << cnt[N];


    return 0;
}