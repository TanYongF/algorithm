//https://acm.njupt.edu.cn/contest/137/board/challenge/E
#include <stdio.h>
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
const int MAXN = 210;
int N, M;
int f[MAXN][MAXN];
int sg(int x, int y) {
    if (f[x][y] != -1) return f[x][y];
    unordered_set<int> S;
    for (int i = 2; i < x-1; ++i)
            S.insert(sg(i, y) ^ sg(x-i, y));
    for (int j = 2; j < y-1; ++j)
            S.insert(sg(x, j) ^ sg(x, y-j));
    for (int i = 0; ; ++i)
        if (!S.count(i))
            return f[x][y] = i;
}

int main(int argc, char * argv[]){
	ms(f,-1);
	while(cin >> N >> M){
		if(!sg(N, M)) cout << "NO" << endl;
		else cout << "YES" << endl;  
	} 
    return 0;
}