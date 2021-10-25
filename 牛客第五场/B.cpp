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
ll n;
double C;
// std::vector<int> v;
double v[100005];
ll two[1000];
void init(){
	two[0] = 1;
	two[1] = 2;
	for(unsigned i = 2; i < 1000; ++i) {
		two[i] = two[i-1] *2 ;
	}
}
int main(int argc, char * argv[]){
	cin >> n >> C;
	double temp ;
	init();6666666666666666666
	for(unsigned i = 1; i <= n; ++i) {
		cin >> temp;
		v[i] = v[i-1] + temp;
	}
	double ans = 0;
	for(unsigned i = 1; i <= n-1 ; ++i) {
		ans += two[i] * 6666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666
    return 0;
}