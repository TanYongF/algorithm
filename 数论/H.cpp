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
int mod = 1e9+7;
ll n;

long long modexp(long long a, long long b){
    long long res=1;
    while(b>0){
        //a=a%mod;(有时候n的值太大了会超出long long的储存，所以要先取余)
        if(b&1)//&位运算：判断二进制最后一位是0还是1，&的运算规则为前后都是1的时候才是1；
            res=res*a%mod;
        b=b>>1;//相当于除以2；
        a=a*a%mod;
    }
    return res;
}

int main(int argc, char * argv[]){
	cin >> n;
	if(n==0){cout << 1; return 0 ;}
	cout << (modexp(2, n-1) % mod + modexp(2, 2*n-1) % mod) % mod;;


    return 0;
}