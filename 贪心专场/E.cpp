#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <string>
#include <cstring>
#include <algorithm>
#include <climits>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <ctime>
#include <vector>
#include <fstream>
#include <list>
#include <iomanip>
#include <numeric>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s) memset(s, 0, sizeof(s))
const int inf = 0x3f3f3f3f;

int T;
int a[105], b[105];
int main(int argc, char * argv[]){
	cin >>T;
	int a_size = 0 , b_size = 0;
	while(T--){
		ms(a);
		ms(b);
		cin >> a_size;
		int max_value = 0;
		int b_max_value = 0;
		for(unsigned i = 1; i < a_size+1; ++i) {
			cin >> a[i];
			a[i] += a[i-1];
			max_value = max(max_value, a[i]);
		}
		cin >> b_size;
		for(unsigned i = 1; i < b_size+1; ++i) {
			cin >> b[i];
			b[i]+= b[i-1];
			b_max_value  = max(b_max_value, b[i]);
		}
		cout << max(0, b_max_value+max_value)  << endl;
	}

	/* code */


    return 0;
}