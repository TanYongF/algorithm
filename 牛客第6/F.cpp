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
const int MAX = 2e5;
int n,m;
ll times[MAX];
ll res = 0 , maxTime = INT_MIN;
ll sum = 0;
bool cmp(int a,int b){
	return  a > b;
}
int main(int argc, char * argv[]){
	// ms(times, 0);
	cin >> m >> n;
	for(int i = 1; i <= m; ++i) {
		// scanf("%d", &times[i]);
		cin >> times[i];
		sum += times[i];
		maxTime = max(maxTime,times[i]);
	}
	// res = max((ll)(sum/m+1), (ll)(maxTime/2)+1);
	res = max(maxTime, sum % n == 0 ? sum/n : sum/n+1);

	// cout << res << endl;
	ll cnt = 1, cur = 0;
	for(int i = 1; i <= m; ++i) {
		if(cur == res){
			cur = 0;
			cnt++;
		}
		if(cur + times[i] <= res){
			cout << 1 << " " << cnt << " " << cur << " " << cur + times[i] << endl;
			cur += times[i];
		}else{
			cnt++;
			// cur = times[i] - (res - cur);
			cout << 2 << " "  << cnt <<  " " <<  0 << " " << times[i] - (res - cur) << " " << cnt-1 << " " << cur << " " << res << " "  << endl; 
			cur = times[i] - (res - cur);
		}
	}
    return 0;
}