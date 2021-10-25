#include <iostream>
#include <cstring>
#include <climits>
#
using namespace std;
static int MAX = INT_MAX;
long long dist[6][50001];
int from[50001], to[50001], value[50001];
bool visted[50001];
int n , m;
int a, b, c, d, e;
long long  result = INT_MAX;
int people[5];
void dijstra(int fromPeopleIndex){
	memset(dist[fromPeopleIndex], 127, sizeof(dist[fromPeopleIndex]));
	dist[fromPeopleIndex][people[fromPeopleIndex]] = 0;
	while(true){
		int min_value = MAX;
		int min_value_index = -1;
		for (int i = 1; i <= 50001; ++i)
		{	
			if(!visted[i] && min_value > dist[fromPeopleIndex][i]){
				min_value_index = i;
				min_value = dist[fromPeopleIndex][i];
			}
		}
		if(min_value_index == -1) break;
		visted[min_value_index] =  true;
		for (int i = 1; i <= 50001; ++i)
		{
			int values;
			if(!visted[i]){
				for (int j = 0; j < 50001; ++j)
				{
					if((from[j] == min_value_index && to[j] == i)
						|| (from[j] == i && to[j]== min_value_index)){
						values = value[j];
						break;
					}
				}
				dist[fromPeopleIndex][i] = min(dist[fromPeopleIndex][i],
					dist[fromPeopleIndex][min_value_index] + values);
			}
		}
	}

}
void dfs(int hasArr, long long currDist, long long  currIndex){
	if(hasArr == 5){
		result = min(result, currDist);
		return;
	}

	for(int i = 0; i < 5; i++){
		if(visted[i]) continue;
		visted[i] = true;
		currDist += dist[currIndex][people[currIndex]];
		dfs(hasArr+1, currDist, people[currIndex]);
		currDist -= dist[currIndex][people[currIndex]];
		visted[i] = false;
	}

}
int main(){
	cin >> n >> m;
	for (int i = 0; i < 5; ++i)
	{
		cin >> people[i];
	}
	int i = 0;
	while(m--){
		scanf("%d %d %d",&from[i],&to[i],&value[i]);
	}
	for (int i = 0; i < 5; ++i)
	{
		dijstra(0);
	}
	dfs(0, 0, 0);
	cout << result;



	return 0;
}