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
const int maxN = 1e6+10;
int mod = 1e9 + 7;
ll p[maxN];
int T;
string str;
stack<char> st;
void Powinit(){
	p[1] = 1;
	for(int i = 2; i < maxN; i++){
		p[i] = ((p[i-1] * 2) % mod + 1) % mod;
	}
}
int main(int argc, char * argv[]){
	Powinit();
	ll ans = 0;
	cin >> str;
	for(unsigned i = 0; i < str.length(); i++){
		if(str[i] == 'a') st.push('a');
		else ans = (ans + p[st.size()]) % mod;
	}
	cout << ans;
    return 0;
}