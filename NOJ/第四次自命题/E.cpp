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
const int N = 10;
int T;
int f[N][N];
int sg(int x, int y) {
	int minxy = min(x,y);
    if (f[x][y] != -1) return f[x][y];
    // if(x == 0 && y == 0) return 0;
   	// cout << "1";
    unordered_set<int> S;               // 哈希表存所有可以到的局面
    //状态取x
    for (int i = 1; y != 0 && i <= x; ++i)
        S.insert(sg(x - i,y));    
    //状态取y
    for (int i = 1; x!= 0 && i <= y; ++i)
        S.insert(sg(x, y-i));
    //取xy
    for (int i = 1; x!=0 && y !=0 && i <= minxy; ++i)
        S.insert(sg(x-i, y-i)); 
           
    for (int i = 0 ; ; ++i)
        if (!S.count(i))
            return f[x][y] = i;
}


int main(int argc, char * argv[]){
	cin >> T;
	int res = 0;

	memset(f, -1, sizeof(f));  
	while(T--){
		int n,m;
		cin >> n >> m;
		res ^= sg(n,m);
	}
		for(int i= 0; i < 10;i++){
		for(int j =0; j < 10; j++){
			cout << f[i][j]<<" ";
		}
		cout << endl;
	}
	cout << res;
	if(res) cout << "Franklin";
	else cout << "Trevor";
	



	


    return 0;
}