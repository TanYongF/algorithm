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
const int mod = 99997867;
int N , D, idx;
int maxx = INT_MIN;
int place[1000010];
vector<int> havP;
int main(int argc, char * argv[]){
	cin >> N >> D;
	memset(place, 0, sizeof(place));
	for(int i = 0; i < N; i++){
		cin >> idx;
		havP.push_back(idx);
		place[idx] = 1;
		maxx = max(maxx, idx);
	}
	ll ans= 0 ;
	for(int i = 0 ; i <= maxx; i++) place[i] += place[i-1];
	for(auto p : havP){
		ll longestPlace = p + D >= maxx ? maxx : p + D;
		ll nums = place[longestPlace] - place[p];
		ans = (ans + (nums-1)*nums/2%mod)%mod;
	}
	cout << ans;
    return 0;
}