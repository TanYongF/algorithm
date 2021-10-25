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
const MAXN = 5005;
int T, size;
int edge[5005][5005];

int x[MAXN], y[MAXN];
int maxX, maxY;
int 
// int slove(){
// 	int maxItem = INT_MIN;
// 	for(unsigned i = 0; i <= size; ++i) {
// 		int curx = x[i], cury = y[i];
// 		for(int j = i + 1; j <= size; j++){
// 			maxItem = max(maxItem,(abs(x[i]-x[j]),abs(y[i]-y[j])));
// 		}
// 		maxX = 
// 	}

// }
int main(int argc, char * argv[]){
	cin >> T;
	while(T--){
		cin >> size;
		for(unsigned i =1; i <= size; ++i) {
			cin >> x[i] >> y[i];
		}
		// slove();
	}

	/* code */


    return 0;
}