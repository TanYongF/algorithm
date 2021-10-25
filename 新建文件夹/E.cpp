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
int T, num;
const int MAXN = 1e5+10; 
int b[MAXN],c[MAXN];
int main(int argc, char * argv[]){
		cin >> num;
		ms(b,0);
		ms(c,0);
		ll ans = 0;
		for(unsigned i = 2; i <= num; ++i) {
			cin >> b[i];
		}
		for(unsigned i = 2; i <= num; ++i) {
			cin >> c[i];
		}
		for(ll i = 0; i <= min(c[2],b[2]); ++i) {
			bool flag = true;
			ll pre = i;
			ll cur ;
			for(unsigned i = 2; i <= num; ++i) {
			 	if(pre > c[i]){flag =false; break;}
			 	cur = c[i] - pre;
			 	if((cur | pre) != b[i]){
			 		flag = false;
			 		break;
			 	}
			 	pre = cur;
			 } 
			 if(flag) {ans++;};
		}
		cout << ans;
    return 0;
}