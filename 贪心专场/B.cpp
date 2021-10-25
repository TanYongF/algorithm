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
#include <climits>
#include <fstream>
#include <list>
#include <iomanip>
#include <numeric>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s) memset(s, 0, sizeof(s))
const int inf = 0x3f3f3f3f;

int n , m;
int res = INT_MAX;
std::vector<int> v;
int main(int argc, char * argv[]){
	cin >> n >> m;
	int pis;
	for(unsigned i = 0; i < m; ++i) {
		scanf("%d" , &pis);
		v.push_back(pis);	
	}
	sort(v.begin(), v.end());
	for(unsigned i = 0; i <= v.size()-n; ++i) {
		res = min(res, v[i+n-1]-v[i]);
	}
	cout <<res;

	/* code */


    return 0;
}