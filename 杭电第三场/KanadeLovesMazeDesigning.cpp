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
// typedef int unsigned int ;
typedef pair<int,int> Node;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s) memset(s, 0, sizeof(s))
const int inf = 0x3f3f3f3f;
const int MAXN = 2005;
int _1[MAXN], _2[MAXN];
int T,n, from ,to;
std::vector<int> v[2005];
int p[2005], c[2005];
int A[2005][2005];
// set<int> st;
int cnt[2005];
int ans;


// set<int> hasV;
// bool hasV[2000];

const ll m = 19560929;
const ll mod1 =1000000007;
const ll mod2 = 1e9+9;

inline void init(int n)
{
	_1[0] = _2[0] = 1;
	for (int i = 1; i <= n; i++)
		_1[i] = 1LL * _1[i - 1] * m % mod1,
		_2[i] = 1LL * _2[i - 1] * m % mod2;
	return ;
}

void add(int x){
	if(cnt[x] == 0) ans++;
	cnt[x]++;
}
void del(int y){
	if(cnt[y] == 1) ans--;
	cnt[y]--;
}
void dfs(int root, int x, int y){
	add(c[x]);
	A[root][x] = ans;
	for(auto f : v[x]) if(f != y) dfs(root,f, x);
	del(c[x]);
}

inline void fadd1(int &x, int y){ x += y; if (x >= mod1) x -= mod1; return ; }
inline void fadd2(int &x, int y){ x += y; if (x >= mod2) x -= mod2; return ; }

// void getA(int root, int curNode){
// 	for(unsigned i = 0; i < v[curNode].size(); ++i) {
// 		int nextNode = v[curNode][i];
// 		// if(A[curNode][nextNode] != 0) continue;
// 		// if(hasV.find(nextNode) != hasV.end())  continue;
// 		if(hasV[nextNode]) continue;
		
// 		int item_num = c[nextNode];

// 		int size1 = st.size();
// 		st.insert(item_num);
// 		// hasV.insert(nextNode);
// 		hasV[nextNode] = true;
// 		int size2 = st.size();
// 		A[root][nextNode] = st.size();
// 		A[nextNode][root] = st.size();

// 		getA(root, nextNode);
// 		auto key = st.find(item_num);
// 		if(size2 != size1) st.erase(key);
// 	}
// }

void clear(){
	ms(p);
	ms(c);	
	for(unsigned i = 0; i <=2000; ++i) {
		v[i].clear();
		ms(A[i]);
	}
	// st.clear();
	// hasV.clear();
	// memset(hasV, false, sizeof(hasV));
}
int main(int argc, char * argv[]){
	cin >> T;
	init(1999);
	while(T--){
		clear();
		cin >> n;
		for(unsigned i = 2; i <= n; ++i) scanf("%d", &p[i]);
		for(unsigned i = 1; i <= n; ++i) scanf("%d", &c[i]);
		for(unsigned i = 2; i <= n; ++i) {
			v[i].push_back(p[i]);
			v[p[i]].push_back(i);
		}
		for(unsigned i = 1; i <= n; ++i) {
			A[i][i] = 1;
		}

		for(unsigned i = 1; i <= n; ++i) {
			// st.clear();
			// hasV.clear();
			ans = 0;
			ms(cnt);
			dfs(i, i, -1);
			// memset(hasV, false, sizeof(hasV));
			// st.insert(c[i]);
			// hasV.insert(i);
			// hasV[i] = true;
			// getA(i,i);
			/* code */
		}

		// for(unsigned i = 1; i <= n; ++i) {
		// 	for(unsigned j = 1; j <= n; ++j) {
		// 		cout << A[i][j] << " ";
		// 	}
		// 	cout << endl;
		// }
		

		for(unsigned i = 1; i <= n; ++i) {
			int sum1 = 0 , sum2 = 0;
			for(unsigned j = 1; j <= n; ++j) {
				fadd1(sum1, 1LL * A[i][j] * _1[j - 1] % mod1);
				fadd2(sum2, 1LL * A[i][j] * _2[j - 1] % mod2);
			}
			cout << sum1 << " " << sum2 << endl;
		}
	}
	/* code */


    return 0;
}