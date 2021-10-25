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
const int MAXN = 1001;
int T;
// int divisor[1001][500];
vector<vector<int>> divisor(1001);
void getdivisor(){
	for(int i = 1; i <= 1000 ;i++){
		for(int j = 1; j <= sqrt(i); j++){
			if(i % j == 0) divisor[i].push_back(j);
		}
	}
}
int main(int argc, char * argv[]){
	int n , m;
	getdivisor();
	cout << " 1";
	cin >> n >> m;
	for()

	int dp[1001][1001];



    return 0;
}