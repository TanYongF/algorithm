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
const int N = 1e7+10;
int a[N];
int T,n;
int main(int argc, char * argv[]){
	int T;
	cin >> T;
	while(T--){
		cin >> n; 
		int ones = 0;    
		char s[30];
   		itoa(n, s, 2);
   		// cout << s << endl;
   		int ans = 0, maxx = INT_MIN;
   		for(int i = 0; i <= 30; i++){
   			if(s[i] == '1') {ans++;ones++;}
   			else ans = 0;
   			maxx = max(ans, maxx);
   		}
   		if(maxx == 1) cout << ones << endl;
   		else cout << maxx << endl;

	}
	


    return 0;
}