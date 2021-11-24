#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;
const int MAXN = 1e5+10;
int T, n,m;
struct node{
	int x, y;
	ll c;
}a[MAXN];
int b[MAXN];
int father[MAXN];
int getF(int val){
	if(father[val] != val) father[val] = getF(father[val]);
	return father[val];
}
void unionSet(int x, int y){
	father[getF(y)] = getF(x);
}
bool cmp(node &n1, node &n2){
	return n1.c > n2.c;
}
int main(int argc, char * argv[]){
	cin >> n >> m;
	for(int i = 0; i < m; i++) cin >> a[i].x >> a[i].y >> a[i].c;
	memset(b, 0, sizeof(b));
	for(int i = 0; i < m; i++) father[i] = i;
	sort(a, a + m, cmp);
	for(int i = 0; i < m; i++){
		int curx = a[i].x, cury = a[i].y;
		if(getF(curx) == getF(cury)){
			cout << a[i].c << endl;
			exit(0);
		}
		if(not b[curx]) b[curx] = cury;
		else unionSet(b[curx], cury);
		if(not b[cury]) b[cury] = curx;
		else unionSet(b[cury], curx);
	}
	cout << 0 << endl;


    return 0;
}