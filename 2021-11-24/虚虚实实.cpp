#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;
const int MAXN = 32;
int T;
int fa[MAXN];
int m,n,k,x,y;
bool flag, ok;
int inDegree[MAXN];
int find(int x){
	if(fa[x] != x) fa[x] = find(fa[x]);
	return fa[x];
}
void unionset(int x, int y){
	if(x > y)swap(x,y);
	fa[find(y)] = fa[find(x)];
}
int main(int argc, char * argv[]){
	cin >> T;
	while(T--){
		cin >> n >> m;
		ms(inDegree, 0);
		for(int i = 1; i <= n; i++) fa[i] = i;
		flag = false;
		ok = true; 

		for(int i = 0; i < m; i++){
			cin >> x >> y;
			inDegree[x]++;
			inDegree[y]++;
			unionset(x,y);
		}
		for(int i = 2; i <= n and ok; i++){
			if(find(i) != find(i-1)){
				cout << "Xun" << endl;
				ok = false;
			} 
		}
		// for(int i = 1; i <= n; i++) cout << find(i) << " ";
		// 	cout << endl;
		if(not ok) continue;

		int s = 0;
		for(int i = 1; i <= n; i++) if(inDegree[i] % 2) ++s;
		flag = (s == 2);
		if(flag) cout << "Zhen" << endl;
		else cout << "Xun" << endl;	/* code */

	}

	


    return 0;
}