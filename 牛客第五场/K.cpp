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

int maxn[100005][100];
int minn[100005][100];
int k[100005][105];
int arr[100005];

int m, n;
void getbestarr(int n)//n为给定的数组的长度  
{  
     int tem = (int)floor(log2((double)n));//因为区间的最长长度是2^tem==n嘛  
   for(int i=1;i<=n;i++)  
        minn[i][0]= maxn[i][0] = arr[i];  
    for(int j=1;j<=tem;j++) //下标从1开始  
     for(int i=1;i+(1<<j)-1<=n;i++)  
    {  
         maxn[i][j] = max(maxn[i][j-1],maxn[i+(1<<(j-1))][j-1]);  //最大值  
         minn[i][j] = min(minn[i][j-1],minn[i+(1<<(j-1))][j-1]);  //最小值  
    }  
}  
int query(int a,int b,bool getwhat)//getwhat表示你是想取最大还是最小  
{  
   int k = log2(b-a+1);  
   if(getwhat)  return max(maxn[a][k],maxn[b-(1<<k)+1][k]);  
   else  return min(minn[a][k],minn[b-(1<<k)+1][k]);  
}  

int main(int argc, char * argv[]){
	cin >> m >> n;
	for(unsigned i = 1; i <= m; ++i) {
		scanf("%d", &arr[i]);
	}
	getbestarr(m);
	for(unsigned i = 0; i < n; ++i) {
		/* code */
	}
	// cout << query(1,3, true);
    return 0;
}