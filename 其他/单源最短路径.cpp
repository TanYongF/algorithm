#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll MAX_VALUE = 1e8;
ll road[6][50001];
int dist[6][50001]

int main()
{
	int n, m, s, t;
	bool visit[6];
	ll dist[2501] = { 0 };
 
	for (int i = 0; i <= 2500; i++)//init
		for (int j = 0; j <= 2500; j++)
			road[i][j] = MAX_VALUE;
	fill(dist, dist + 2501, MAX_VALUE);
	scanf("%d %d %d %d", &n,&m,&s,&t);
	dist[s] = 0;
	while (m--)
	{
		int a, b,c;
		scanf("%d %d %d", &a,&b,&c);
		if (c<road[a][b])
			road[a][b] = road[b][a] = c;
	}
 
	while (1)
	{
		int min_cost = MAX_VALUE, min_cost_index = -1;
		for (int i = 1; i <= n; i++)
		{
			if (!visit[i] && min_cost>dist[i])
			{
				min_cost = dist[i];
			min_cost_index = i;
			}
		}
		if (min_cost_index == -1)break;
		visit[min_cost_index] = 1;
 
		for (int i = 1; i <= n; i++)
		{
			if (!visit[i])
			{
				dist[i] = min(dist[i], dist[min_cost_index] + road[min_cost_index][i]);
			}
		}
	}
 
	cout << dist[t];//output
	return 0;
}
