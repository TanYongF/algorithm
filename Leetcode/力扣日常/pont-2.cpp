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
int have[26];
int main(int argc, char * argv[]){
	int n,m;
	ms(have,0);
	string a, b;
	ll ans= 0;
	cin >> n >> m >> a >> b;
	for(auto ch : a) have[ch-'a']++;
	for(int l = 0, r = 0;  r < b.length(); r++){
		//如果可以装下最后一个字母,那么就装下
		if(have[b[r]-'a']>=0) --have[b[r]-'a'];
		//如果最后一个字母装不下,那么左边的指针往前移动,直到其可以装下, 如果都装不下,那么L=r
		while(have[b[r]-'a'] < 0 && l <= r){
			++have[b[l++]-'a'];
		} 
		ans +=  r - l + 1;
	}
	cout << ans;
    return 0;
}