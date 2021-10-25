//题目链接：https://loj.ac/p/130
//区间修改，单点查询
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

const int MAXN = 1e6+10;
ll a[MAXN]; //差分数组
ll b[MAXN]; //原数组
ll c[MAXN]; //d[i]*i	
int n, q;
ll t[MAXN];	//差分树状数组
ll t2[MAXN];//d[i]*i树状数组

int lowbit(int x) {return x&-x;}

//建树
void bulid(ll* source, ll * target){
	for(unsigned i = 1; i <= n; ++i) {
		target[i] += source[i];
		int j = i + lowbit(i);
		if(j <= n) target[j] += target[i];
	}
}

//单点更新
void point_add(int x, int k){
	for(unsigned i = x; i <= n; i+=lowbit(i)) {
		t[i] += k;
		t2[i] += (ll)k * x;
	}
}

//区间更新
void range_add(int l , int r, int k){
	point_add(l, k);
	point_add(r+1, -k);
}

//区间查询
ll point_sum(int x){
	ll ans = 0;
	for(int i = x; i > 0; i -= lowbit(i)) ans += (x+1)*t[i] - t2[i];
	return ans;
}

//单点查询
ll range_sum(int l, int r){
	return point_sum(r) - point_sum(l-1);
}



int main(int argc, char * argv[]){
	cin >> n>> q;
	ms(a,0);
	ms(b,0);
	ms(c,0);
	ms(t,0);
	ms(t2,0);
	for(unsigned i = 1; i <= n; ++i) {
		// cin >> a[i];
		cin >> b[i];
		a[i] = b[i] - b[i-1];
		point_add(i,a[i]);
		// c[i] = a[i] * i;
		// point_add(i,c[i]);
	}
	// bulid(a,t);
	// bulid(c,t2);
	int type;
	int from,to,num;
	for(unsigned i = 0; i < q; ++i) {
		cin >> type;
		if(type == 1){
			cin >> from >> to >> num;
			range_add(from, to, num);
		}else{
			cin >> from >> to;
			cout << range_sum(from, to) << endl;
		}
	}
    return 0;
}