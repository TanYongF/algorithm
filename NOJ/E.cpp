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
const int MAXN = 10010;
int S,P;
int T;
int P[MAXN][2];
int dis[MAXN][MAXN];
int main(int argc, char * argv[]){
	cin >> S >> P;
	for(int i = 1; i <= P, i++){
		cin >> P[i][0] >> P[i][1];
	}
	for(int i = 1; i <= P; i++){
		for(int j = 1; j <= P; j++){
			dis[i][j] = pow((P[i][0]-P[j][0]),2) + pos((P[i][1]-P[j][1]),2);
			dis[j][i] = dis[i][j];
		}
	}
    return 0;
}