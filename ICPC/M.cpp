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
#include <bitset>
#include <iostream>
#include <list>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;

int T,n;
int main(int argc, char * argv[]){
	cin >> n;
	int bit;
	ll a= 0 , b = 0;
	ll bits[61], sign[61];
	bits[0] = 1; 
	for(int i = 1; i <= 60; i++) bits[i] = bits[i-1] * 2;
	for(int i = 1; i <= 60; i++) cout << bit[i] << " ";
	for(int i = 0; i < n; i++) cin >> sign[i];
	for(int i = 0; i < n; i++){
		cin >> bit;
		if(bit) a += sign[i] * bits[i];
	}
	for(int i = 0; i < n; i++){
		cin >> bit;
		if(bit) b += sign[i] * bits[i];
	}
	bitset<65> bt(a + b);
	cout << bt[0];
	for(int i = 1; i < n; i++) cout << " " << bt[i];

    return 0;
}