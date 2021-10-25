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

int T,n;
vector<bool> ans;
vector<int> ret;
int main(int argc, char * argv[]){
	cin >> T;
	int m  = T;
	int item[T+1];
	ans = vector<bool>(T+1);
	while(m--){
		for(int i = 1; i <= T; i++)	cin >>item[i];
		for(int i = 1; i <= T; i++) if(!ans[item[i]]){ ret.push_back(item[i]); ans[item[i]] = true; break;}
	}
	for(auto it : ret) cout << it << " ";
    return 0;
}