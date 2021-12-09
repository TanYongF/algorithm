//https://acm.njupt.edu.cn/contest/130/board/challenge/H
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;
const int MAXN = 305;
int T;
int a[MAXN];
int w[MAXN][MAXN];
int fa[MAXN];
bool hasV[MAXN];
int getfa(int val){
	if(fa[val] != val) fa[val] = getfa(fa[val]);
	return fa[val];
}
void merge(int a, int b){
	int faa = getfa(a), fab = getfa(b);
	if(faa > fab) swap(faa, fab);
	fa[fab] = faa;
}
int main(int argc, char * argv[]){
	ll ans = 0;
	cin >> n;
	ms(hasV, false);
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin >> w[i][j];
	for(int i = 0; i < n; i++){
		int need = a[i];
		for(int j = 0; j < n; j++){
			if()
		}
	}


    return 0;
}