
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
struct node
{
    int u,v;
    ll w;
    node(int a,int b,ll x):u(a),v(b),w(x){}
};
vector<node> edge;
int vn,an;
int pa[5005];
int x[5005], y[5005];
bool cmp(const node &a,const node &b)
{
    return a.w<b.w;
}
int find(int x)
{
    return x==pa[x]?x:pa[x]=find(pa[x]);
}
int kruskal()
{
    ll sumw=0;
    int cnt=0;
    for(int i=1;i<=vn;i++) pa[i]=i;
    ll Max = -1;
    for(int i=0;i<an;i++)
    {
        int x=find(edge[i].u),y=find(edge[i].v);
        if(x!=y)
        {
            pa[x]=y;
            sumw+=edge[i].w;
            Max = max(edge[i].w, Max);
            ++cnt;
        }
        if(cnt==vn-1) break;
    }
    return Max;
}
int main()
{
    int T;
    cin>>T;
    while(T--){
        cin>>vn;
        edge.clear();
        ms(pa,0);
        for(int i=1;i<=vn;i++){
            cin >> x[i] >> y[i];
        }
        for(int i = 1; i <= vn; i++){
            for(int j = i+1; j <= vn; j++){
                ll len = 1.L * (x[i]-x[j]) * (x[i]-x[j]) + 1.L*(y[i]- y[j])*(y[i]-y[j]);
                edge.push_back(node(i, j, len));
            }
        }

        an = edge.size();
        sort(edge.begin(),edge.end(),cmp);
        // int maxL = kruskal();
        // cout<<kruskal()<<endl;
        printf("%.1lf\n", (double)kruskal());
    }
    return 0;
}