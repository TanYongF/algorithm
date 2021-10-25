#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <string>
#include <cstring>
#include <algorithm>
#include <climits>
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
#define ms(s) memset(s, 0, sizeof(s))
const int inf = 0x3f3f3f3f;

int T;
ll ret = 0;
ll mina = INT_MAX, minb = INT_MAX;
ll a[55];
ll b[55];
int m;

int main(int argc, char * argv[]){
	ms(a);
	ms(b);
	 cin >> T;
	 while(T--){
	 	ret = 0;
	 	mina = INT_MAX;
	 	minb = INT_MAX;
	 	cin >> m;
	 	for(unsigned i = 0; i < m; ++i) {
	 		scanf("%d", &a[i]);
	 		mina = min(mina, a[i]);
	 	}
	 	for(unsigned i = 0; i < m; ++i) {
	 		scanf("%d", b[i]);
	 		minb = min(minb,b[i]);
	 	}
	 	for(unsigned i = 0; i < m; ++i) {
	 		int num ;
	 		num = max(a[i]-mina, b[i]-minb);
	 		ret += num;
	 	}
	 	cout << ret << endl;
	 }
    return 0;
}