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

int T; 
ll p;
int main(int argc, char * argv[]){
	cin >> T;
	while(T--){
		cin >> p;
		cout << 6*p  <<" " << 3 << endl;
		cout << p << " " << 2 * p << " " << 3 * p << endl;
	}

    return 0;
}