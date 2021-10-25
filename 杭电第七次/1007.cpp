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
#include <queue>
#include <map>
#include <ctime>
#include <climits>
#include <unordered_map>
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
const int MAXN = 1e5 + 10;
int T, n, num;
int a[MAXN], din[MAXN];
queue<int> Q;
int main(int argc, char * argv[]){
	cin >> T; 
	while(T--){
		scanf("%d",&n);
		ms(a,0); ms(din,0);
		for(unsigned i = 1; i <= n; ++i) {
			scanf("%d",&a[i]);
			din[a[i]]++;
		}
		for(unsigned i = 1; i <= n; ++i) {
			if(din[i] == 0){
				Q.push(i);
			}
		}
		while(!Q.empty()){
			int u = Q.front();
			din[a[u]]--;
			if(din[a[u]] == 0){
				Q.push(a[u]);
			}
			Q.pop();
		}
		ll q = -1, p = -1;
		int j;
		bool flag = true;
		for(unsigned i = 1; i <= n; ++i) {
			if(din[i] == 0) continue;
			ll tp = 0, tq = 0;
			j = i;
			for(; din[j] ; j = a[j]){
				tp++;
				tq += a[j];
				din[j] = 0;
			}
			if(q == -1){
				p = tp;
				q = tq;
				continue;
			}
			if(1.L * tq * p != 1.L * q * tp){
				cout << "NO" << endl;
				flag = false;
				break;
			}
		}
		if(flag) cout <<"YES" << endl;
	}
    return 0;
}