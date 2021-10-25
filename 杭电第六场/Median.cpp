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
const int MAXN = 1e5+10;
int T, n, m;
int position[MAXN];
int maxD = INT_MIN, maxFromIndex;
ll zeroSum = 0;
int main(int argc, char * argv[]){
	cin >> T;
	while(T--){
		maxD = 0;
		// v.clear();
		cin >> n >> m;
		for(unsigned i = 1; i <= m; ++i) {
			cin >>  position[i]; 
		}
		sort(position+1, position+m);
		position[m+1] = n+1;
		zeroSum = n - m;
		for(unsigned i = 1; i <= m+1; ++i) {
			if(position[i] - position[i-1] > maxD){
				maxD = position[i] - position[i-1] - 1;
				maxFromIndex = position[i-1] + 1;
			}
		}

		if(2*maxD - zeroSum >= maxFromIndex) cout << "NO" << endl;
		else cout << "YES" << endl;
	}


    return 0;
}