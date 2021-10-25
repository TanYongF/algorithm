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
int bits[2][1005];
int n,m;
void init(){
	bits[0][0] = 0;
	bits[0][1] = 0;
	bits[1][0] = 1;
	bits[1][1] = 1;
	for(unsigned i = 2; i < 1005; ++i) {
		bits[0][i] = bits[0][i-1] == bits[0][i-2] ? 1- bits[0][i-1] : bits[0][i-1];
		bits[1][i] = bits[1][i-1] == bits[1][i-2] ? 1- bits[1][i-1] : bits[1][i-1];
		/* code */
	}
}
int main(int argc, char * argv[]){
	cin >> n >> m;
	init();
	for(unsigned i = 0; i < n; ++i) {
		for(unsigned j = 0; j < m; ++j) {
			if(i % 2 == 0) cout << bits[0][j];
			else cout << bits[1][j] ;
		}
		cout << endl;
	}

    return 0;
}