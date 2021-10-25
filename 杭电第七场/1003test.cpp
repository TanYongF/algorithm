#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cctype>
#include <cmath>
#include <climits>
#include <cstdlib>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <list>
#define ms(s,val) memset(s, val, sizeof(s))
typedef long long ll;
using namespace std;
const int maxn=5005;
ll ma[maxn][maxn];
int x[maxn], y[maxn];
ll dis[maxn];
int vis[maxn];
int n;
int prim()
{
	ms(dis, 0);
	int i,t=1;
	memset(vis,0,sizeof(vis));
	vis[0]=1;
	for(i=1;i<n;i++)
		dis[i]=ma[0][i];
	ll ans=INT_MIN;
	while(t++<n)
	{
		int k;
		ll Min=INT_MAX;
		for(i=1;i<n;i++)
		{
			if(Min>dis[i]&&!vis[i])
			{
				Min=dis[i];
				k=i;
			}
		}
		vis[k]=1;
		if(ans<Min)
			ans=Min;
		for(i=1;i<n;i++)
			if(dis[i]>ma[k][i]&&!vis[i])
			dis[i]=ma[k][i];
	}
	return ans;
}
int main()
{
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		ms(x,0);
		ms(y,0);
		for(int i = 0; i < n; i++) cin >> x[i] >> y[i];
		for(int i=0;i<n;i++)
			for(int j=i;j<n;j++){
				ma[i][j] = 1.L * (x[i]-x[j]) * (x[i]-x[j]) + 1.L*(y[i]- y[j])*(y[i]-y[j]);
				ma[j][i] = 1.L * (x[i]-x[j]) * (x[i]-x[j]) + 1.L*(y[i]- y[j])*(y[i]-y[j]);
			}
		for(int i =0; i <n ;i++){
			for(int j = 0; j <n ;j++){
				cout << ma[i][j] << " ";
			}
			cout << endl;
		}
		ll result = prim();
		printf("%.1lf\n", (double)result);
	}
	return 0;
}
