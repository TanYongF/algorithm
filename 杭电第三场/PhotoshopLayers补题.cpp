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
const int MAX = 100005;
int q,n,T;
int f[MAX], a[MAX],b[MAX],c[MAX]; //代表i的第一个普通方式的下标
int ask(int *num, int l ,int r){
	//找到r右端点的前面第一个普通方式，那么也就意味着从此开始才有作用
	int t = f[r] ;
	int res = 0;
	//判段t和l的关系，如果 t < l,那么就是[l,r]这一段的前缀和，否则就是[t,r]这一段
	if(t < l) res = num[r] - num[l-1];
	else      res = num[r] - num[t-1];
	return (res > 255) ? 255 : res;

}
int main(int argc, char * argv[]){
	cin >> T;
	while(T--){
		ms(f);
		ms(a);
		ms(b);
		ms(c);
		cin >> n >> q;
		int m;
		int num = 0;
		for(unsigned i = 1; i <= n; ++i) {
			//从最低位置依次往高
		 	scanf("%d%X",&m, &num);
		 	a[i] = a[i-1] + (num & 255);
		 	num >>= 8;
		 	b[i] = b[i-1] + (num & 255);
		 	num >>= 8;
		 	c[i] = c[i-1] + (num & 255);

		 	//如果为1，那么就是普通，则其左边第一个普通就是其自身
		 	if(m == 1) f[i] = i;
		 	else f[i] = f[i-1];
		 } 
		  //   for(unsigned i = 0; i <= n; ++i) {
    //   // cout << f[i] << " ";
    //   printf("%d", f[i]);
    // }
		 for(unsigned i = 0; i < q; ++i) {
		 	int from,to;
		 	scanf("%d %d", &from, &to);
		 	printf("%02X%02X%02X\n",ask(c,from,to),ask(b,from,to),ask(a,from,to));
		 }
	
	}


    return 0;
}