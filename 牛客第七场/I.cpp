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
int bits[35],bitx[35];
ll x,y,s ;
int main(int argc, char * argv[]){
	cin >> x >> s;
	bool flag =false;
	flag = (x == s);
	for(unsigned i = 1; i < 35; ++i) {
		bits[i] = s & 1;
		bitx[i]  = x & 1;
		s >>= 1;
		x >>= 1;
	}
	if(x != 0) {cout << 0; return 0;};
	ll res = 1;
	for(unsigned i = 1; i < 35; ++i) {
		if(bitx[i] == 1 && bits[i] == 0){
			cout << 0;
			return 0;
		}
		if(bits[i] == 1 && bitx[i] == 1){
			res *= 2;
		}
	}
	if(flag) res -= 1;
	cout << res;
    return 0;
}