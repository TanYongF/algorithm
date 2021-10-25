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

int T;
int n;
int main(int argc, char * argv[]){
	cin >> T;
	while(T--){
		string ans;
		cin >> n;
		int mod4 = n % 4;
		if(mod4 == 1) ans += "1";
		else if(mod4 == 2) ans += "0001";
		else if(mod4 == 3) ans += "01";
		int size = n / 4;
		while(size--) ans += "1001";
		cout << ans.length() << "\n" << ans << endl; 
	}

	


    return 0;
}