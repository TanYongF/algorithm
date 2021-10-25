//https://acm.hdu.edu.cn/showproblem.php?pid=1466
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
const int N = 21, MAXN = N*(N-1)/2;
bool dp[N][N*(N-1)/2+1]; //n个交点一共有Cn2个交点.
void initI(){
	memset(dp, 0, sizeof(dp));
	dp[1][0] = 1;
	dp[0][0] = 1;
	for(int i = 2; i < N; i++){		//遍历所有元素
	   for(int j = 1; j <= i; j++){	//遍历平行直线的条数
	      int b = i - j;  					//其他非平行直线条数
	      for(int k = 0; k <= b*(b-1)/2; k++){//遍历非平行直线所有交点可能
	         if(dp[b][k]) dp[i][b*j+k] = true;	//更新状态
	      }
	   }
	}
}

int main(int argc, char * argv[]){
	initI();
	int  n;
	while(cin >> n){
		cout << "0";
		for(int i = 1; i <= n*(n-1)/2; i++){
			if(dp[n][i]) cout << " " << i;
		}
		printf("\n");

	}

    return 0;
}