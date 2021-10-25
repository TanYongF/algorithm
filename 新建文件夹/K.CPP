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

#define pi 3.14159265358979323846   // pi
const int inf = INT_MAX;

int T;
ll cal(ll a, double PI){
	ll res = 0;
	ll cur = a;
	while(cur < PI){
		cur += a;
		res++;
	}
	return res;
}
int main(int argc, char * argv[]){
	/* code */
	double PI = pi;
	cin >> T;
	double a, b;
	ll za, zb;
	ll minL;
	while(T--){
		cin >> a >> b;
		za = a * 1e9;
		zb = b * 1e9;
		PI = pi * 1e9;
		ll minL = min(za,zb);
		// cout << minL << endl;
		if(minL > PI){
			cout << 4 << endl;
			continue;
		}else{
			ll size = cal(minL,PI);
			if(size * minL < PI ) cout << 2 * (size + 2) << endl;
			else cout <<  2.L * (size) << endl;
		}
	}
    return 0;
}