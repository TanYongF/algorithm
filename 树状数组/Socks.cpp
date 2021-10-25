//题目链接 ： https://vjudge.net/contest/448273#problem/A
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
#include <unordered_map>
#include <numeric>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;

const int MAXN = 2e5+10;
int father[MAXN];
int findset(int x)//查    
{    
    if(x != father[x])    
        father[x]=findset(father[x]);//查的过程中进行路径压缩，有效加快并查集运算    
    return father[x];    
}    
    
int unionset(int a, int b)//并    
{    
    int x=findset(a);    
    int y=findset(b);    

    if(x != y)     //不在同一根上，进行合并操作      
        father[y]=x;
    return 0;    
}   
int n,m,l,r,k,f;
int colors[MAXN];
bool used[MAXN];
ll ans = 0;
unordered_map<int,int> mp;
unordered_map<int, set<int>> mst;
unordered_map<int, int> colornum;
std::vector<int> v[MAXN];
int main(int argc, char * argv[]){
	// cout << MAXN ;
	cin >> n >> m >> k;
	ms(used,false);

	for(unsigned i = 1; i <= n; ++i) father[i] = i;
	for(unsigned i = 1; i <= n; ++i) cin >> colors[i];
	for(int i = 0; i < m; i++){
		cin >> l >> r;
		used[l] = true;
		used[r] = true;
		unionset(l,r);
	}
	for(unsigned i = 1; i <= n; ++i) {
		cout << father[i] << " " ;
	}
    // for(int i=1;i<=n;i++)//通过vector数组来确定每一个集合中的元素所对应的颜色
    //     v[findset(i)].push_back(colors[i]);
    // int ans=0;
    // for(int i=1;i<=n;i++)
    // {
    //     if(v[i].size()<=1)
    //         continue;
    //     map<int,int>mps;
    //     int maxx=0;
    //     for(int j=0;j<v[i].size();j++)//遍历集合中的颜色，找出出现次数最多的颜色
    //     {
    //         mps[v[i][j]]++;
    //         maxx=max(maxx,mps[v[i][j]]);
    //     }
    //     // cout << maxx << endl;
    //     ans+=v[i].size()-maxx;
    // }

	for(unsigned i = 1; i <= n; ++i) {
		if(!used[i]) continue;
		int fi = findset(i);
		int f = colors[fi];
		
		// if(m==200000) cout << "f:" << f << endl;
		mp[f]++; //这一个连通块总数加1
		mst[f].insert(colors[i]);//将这个颜色加入
		colornum[colors[i]]++;
	}
	// if(m == 200000) cout << "mp[1]:" << mp[1] << "colornum[1]: " <<  colornum[1] <<"colornum[2]: " << colornum[2] << endl;   
	//遍历所有森林
	for(auto m : mp){
		int key = m.first;
		int colorSum = m.second; //改森林的所有节点数
		int maxColorNum = INT_MIN;//改森林中数量最多的元素的数量
		for(int it : mst[key]){//遍历这个树的所有节点
			maxColorNum = max(maxColorNum, colornum[it]);//找到最大元素
		}
		cout <<  "maxColorNum: " << maxColorNum << "colorSum: "  << colorSum << endl;
		ans += (colorSum - maxColorNum);
	}
	cout << ans;
    return 0;
}