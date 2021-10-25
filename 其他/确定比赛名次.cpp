#include <iostream>
#include <climits>
#include <cstring>
using namespace std;
int N, M;
bool map[501][501]; 
int indegree[510];
void getResult(){
	int cur;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			if(indegree[j] == 0){
				cur = j;
				break;
			}
		}
		if(i == N-1){
			printf("%d\n", cur);
		}else{
			printf("%d ",cur);
		}
		indegree[cur]--;
		for (int k = 1; k <= N; ++k)
		{
			if(map[cur][k]){
				indegree[k]--;
			}
		}
	}
}
int main(){
	while(scanf("%d%d",&N,&M) != EOF){
        memset(indegree,0,sizeof(indegree));///初始化为0
        memset(map,false,sizeof(map));
		for (int i = 0; i < M; ++i)
		{
			int pre ,later;
			cin >> pre >> later;
			if(!map[pre][later]){
				map[pre][later] = true; 
				indegree[later] += 1;
			}
			
		}
		getResult();
	}
	return 0;
}