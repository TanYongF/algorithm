#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <string>
#include <cstring>
#include <algorithm>
#include <unordered_map>
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
int n;
char bit[5000000];
int g(int n) { return n ^ (n >> 1); }
int main(int argc, char * argv[]){
	cin >> n;
	ll sum = pow(2, n);
	bit[0] = '1';
	for(int i = 1; i < sum; i++){
		bit[g(i)] = bit[g(i-1)] == '1' ? '0' : '1';
	}

	// cout << g(sum-1) << endl;
	// cout << bit[g(sum-1)] << endl
	bit[g(sum-1)] = '1';
	string ans(bit);
	cout << ans << endl;
    return 0;
}