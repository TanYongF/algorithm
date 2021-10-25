#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <string>
#include <cstring>
#include <priority_queue>
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
typedef pair<int,int> P;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = 1e6+10;
string sq;
int T,n;
priority_queue<P> pq; 
map<int,int> mp(inf);
stack<int> sk;
bool hasVisted[inf];
void slove(string sq,int n){
[]

}

int main(int argc, char * argv[]){
	cin >> n;
	cin >> sq;
	for(unsigned i = 0; i < n; ++i) {
		int color = 0;
		cin >> color;
		mp[color]++;
	}
	for(auto it : mp) {
		P pp = P(it.second, it.first);
		pq.push(P);
	}
	slove(sq, n);
    return 0;
}