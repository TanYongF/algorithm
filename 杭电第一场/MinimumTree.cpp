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
#include <vector>
#include <fstream>
#include <list>
#include <iomanip>
#include <numeric>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s) memset(s, 0, sizeof(s))
const int inf = 0x3f3f3f3f;

const int N = 1e7+7;
int pri[N];	//存储素数
int cnt = 0;		//素数的个数
bool ispri[N];	//是否为素数
int ans[N];
int getPri(){
	for(int i = 2; i < N; i++){
	   ispri[i] = true;
	}
	for(int i = 2; i < N; i++){
	   if(ispri[i]){
	      pri[cnt++] = i;
	   }
	   for(int j = 0; j <= cnt; j++){
	      if(i * pri[j] >= N) break;
	      ispri[i * pri[j]] = 0;		//不满足条件 剔
	      if(i % pri[j] == 0) break;	//后面的不找了
	   }
	}

}


int main(int argc, char * argv[]){
	getPri();
	ms(ans);
	int T , m;
	ll res= 0;
	cin >> T;
	for(int i = 3; i < N; i++){
		if(ispri[i]) ans[i] = ans[i-1] +  (i << 1);
		else  		 ans[i] = ans[i-1] + i; 
	}
	while(T--){
		cin >> m;
		cout << ans[m] << endl;
	}

    return 0;
}