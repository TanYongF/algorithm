#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <string>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <climits>
#include <vector>
#include <iostream>
#include <list>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;

int n, ans = 0;
int main(int argc, char * argv[]){
	cin >> n;
	int last = 1024 - n;
	int four = last / 64;
	last -= four * 64;
	int three = last / 16;
	last -= three * 16;
	int two = last / 4;
	last -= two * 4;
	// cout << four << three << two << last << endl;
	cout << last + two + three + four;
    return 0;
}