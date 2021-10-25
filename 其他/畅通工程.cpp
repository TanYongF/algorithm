#include<cstdio>
#include<cstring>
using namespace std;
 
const int INF=0x3f3f3f3f;
 
int a[1005][1005],dis[1005];
bool vis[1005];
int n,ant;
int prim()
{
    int i,j;
    for(i=1; i<=n; i++)
    {
        dis[i]=a[1][i];
        vis[i]=false;
    }
    vis[1]=true;
    for(i=1; i<n; i++)
    {
        int minn=INF;
        int p;
        for(j=1; j<=n; j++)
        {
            if(!vis[j]&&dis[j]<minn)
            {
                minn=dis[j];
                p=j;
            }
        }
        vis[p]=true;
        ant=ant+minn;
        for(j=1; j<=n; j++)
        {
            if(!vis[j]&&dis[j]>a[p][j])
            {
                dis[j]=a[p][j];
            }
        }
    }
    return ant;
}
int main()
{
    while(scanf("%d %d",&n, &m)!=EOF&&n)
    {
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                a[i][j]=INF;
        for(int i=1; i<=m; i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            a[x][y]=a[y][x]=z;
        }
        if(m <= n-2){
        	cout << "?" << fa
        }
        ant=0;
        prim();
        printf("%d\n",ant);
    }
    return 0;
}
