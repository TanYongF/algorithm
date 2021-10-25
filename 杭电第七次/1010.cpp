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
int T;
double q, p;
int main(int argc, char * argv[]){
	cin >> T;
	while(T--){
		cin >> p >> q;
		if(q > p || abs(p - q) < 1e-6)  cout << "N0 M0R3 BL4CK 1CE TEA!" << endl;
		else cout << "ENJ0Y YOURS3LF!" << endl;
	}
    return 0;
}