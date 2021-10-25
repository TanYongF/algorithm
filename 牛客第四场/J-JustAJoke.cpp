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
#include <vector>
#include <fstream>
#include <list>
#include <iomanip>
#include <numeric>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s) memset(s, -1, sizeof(s))
const int inf = 0x3f3f3f3f;


const int maxn=1005;
int m,n;
set<int> st[105];
int nums[105];
int pa[maxn];//父节点 
int find(int x){
	if(pa[x]==-1) return x;//根的父节点为-1 
	else{
		int tmp = find(pa[x]);//找到父节点的根； 
		pa[x] = tmp;//路径压缩，路径上的节点父节点都指向根 
		return tmp;//返回根 
	}
}

int main(int argc, char * argv[]){
	cin >> n >> m;
	ms(pa);
	int from, to;
	for(unsigned i = 0; i < m; ++i) {
		scanf("%d %d", &from, &to);
		int fromfather = find(from);
		int tofathere  = find(to);
		if(fromfather != tofathere){
			pa[fromfather] = tofathere;
		}
	}
	ll res = 0;
	for(unsigned i = 1; i <= n; ++i) {
		nums[find(i)]++;
	}
	for(unsigned i = 1; i <= n; ++i) {
		// cout << nums[i];
		// nums[i] %= 2;
		if(nums[i] == 0) continue;
		res ^= 1;
	}
	// cout << res;
	if(!res) cout << "Bob" ;
	else 			cout << "Alice" ;
	return 0;
}