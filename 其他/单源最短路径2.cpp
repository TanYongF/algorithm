#include <iostream>
#include <climits>
using namespace std;
int n, m, start, endIndex;
int ways[2501][2501];			
long long dist[2501];
bool visited[2501] = {false};
int main(){
	cin >> n >> m >> start >> endIndex;
	//路径默认为极大值
	for (int i = 0; i <= 2500; i++)//init
		for (int j = 0; j <= 2500; j++)
			ways[i][j] = INT_MAX;
	fill(dist, dist + 2501, INT_MAX);
	//填充路径
	for(int i = 0; i < m; i++){
		int from , to, value;
		scanf("%d %d %d",&from, &to, &value);
		if(value < ways[from][to]){
			ways[from][to] = ways[to][from] = value; 
		}
	}
	//初始化
	dist[start] = 0;
	int min_value_index, min_value; //定义每次从集合U中最小路径下标以及最小路径
	while(true){
		min_value_index = -1;
		min_value = INT_MAX;
		//找到集合U中的最小路径下标和最小路径
		for(int i = 1; i <= n; i++){
			if(!visited[i] && min_value > dist[i]){
				min_value_index = i;
				min_value = dist[i];
			}
		}
		//如果所有节点都已经遍历过找到最小路径长度，那么直接跳出。
		if(min_value_index == -1) break;
		//将min_value_index元素加入到visited中
		visited[min_value_index] = true;
		//遍历更新U集合中每一个节点的距离
		for(int i = 1; i <= n; i++){
			if(!visited[i]){
				dist[i] = min(dist[i], dist[min_value_index] + ways[min_value_index][i]);
			}
		}
	}
	// print answer
	cout << dist[endIndex];
	return 0;
}