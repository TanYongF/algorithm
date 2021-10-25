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
int taskNum, dependN;
std::vector<int> v[100005];
bool must[100005];
int temp;
bool hasV[100005];
void dfs(int x, int y){
	hasV[x] = true;
	for(auto f : v[x]){
		if(!must[f] || f == y) continue;
		else dfs(f,x); 
	}
}
int main(int argc, char * argv[]){
	ll ret = 0;
	ms(must, false);
	ms(hasV, false);
	cin >> taskNum >> dependN;
	for(unsigned i = 0; i < taskNum; ++i) {
		scanf("%d", &temp);
		must[i] = temp;
	}
	int from, to;
	for(unsigned i = 0; i < dependN; ++i) {
		cin >> from >> to;
		v[from].push_back(to);
		v[to].push_back(from);
	}
	for(unsigned i = 0; i < taskNum; ++i) {
		if(hasV[i] || !must[i]) continue;
		else{
			dfs(i, -1);
			ret++;
		}
	}
	cout << ret;
    return 0;
}