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

int gcd(int a, int b){
	if(b == 0 ) return a;
	return gcd(b, a % b);
}
int lcm(int a, int b){
	return a * b / gcd(a,b);
}
int a[51];
int main(int argc, char * argv[]){
	int n, m;
	long long res = 1;
	cin >> n;
	for(unsigned i = 0; i < n; ++i) {
		cin >> a[i];
	}
	int x;
	cin >> x;
	for(unsigned i = 0; i < n; ++i) {
		if(x % a[i] == 0){
			res = lcm(res, a[i]);
		}
	}
	if(res % x ==0 ){
		cout << "Possible";
	}else{
		cout << "Impossible";
	}

	/* code */


    return 0;
}