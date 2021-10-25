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
// #define mod 1000000007;
const int mod = 1000000007;

long long modexp(long long a, long long b, int mod)
{
    long long res=1;
    while(b>0)
    {
        //a=a%mod;(有时候n的值太大了会超出long long的储存，所以要先取余)
        if(b&1)//&位运算：判断二进制最后一位是0还是1，&的运算规则为前后都是1的时候才是1；
            res=res*a%mod;
        b=b>>1;//相当于除以2；
        a=a*a%mod;
    }
    return res;
}
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        long long int n;
        cin >> n;
       	ll s1, s2, s3;
       	// ll npow2 = modexp(n, 2, mod);
       	// ll nplusonepow2=modexp(n+1, 2, mod);
       	// ll twonplus1 = (2*n+1)%mod;
       	// ll n4 = modexp(n,4,mod);
       	// ll npow2plus1 = (npow2+1)%mod;
       	// ll nplus1 = (n+1)%mod;
         ll nplusonepow2 =(((n+1)%mod) * ((n+1)%mod)) % mod;
        ll npow2 = (((n)%mod) * ((n)%mod)) % mod;
        ll nplus2pow2 = (((n+2)%mod) * ((n+2)%mod)) % mod;
       	// ll n_pow_2_plus_n = (npow2 % mod + n % mod) % mod; 
        //底面
       	s1 = ((npow2%mod)*(nplusonepow2%mod))%mod;
       	s1 = (((s1 % mod) * ((twonplus1%mod)%mod)) / 12) % mod;
       	// s1 = (((npow2%mod)*(nplusonepow2%mod)*(twonplus1%mod))%mod)/12;
       	s2 = ((n4%mod)*(nplusonepow2%mod)) % mod;
       	s2 =  (( s2 * (twonplus1%mod) )%mod)/12 ;//最大


        ll s4 = ((n % mod)* ((n-1)%mod) )% mod;
         // cout << "S4::" << s4 << endl;
         // cout << modexp(n+2, 2 , mod) << endl;
        
        s4 = ( (s4 % mod)* nplus2pow2) % mod;
         // cout << "S4::" << s4 << endl;
        
        s4 =((s4%mod) * nplusonepow2) % mod;
         // cout << "S4::" << s4 << endl;
         
        ll temp = (2 * npow2) % mod;
         // cout << "S4::" << s4 << endl;
        temp = ((temp % mod) * nplusonepow2) % mod;
         // cout << "S4::" << s4 << endl;
        temp = (temp * twonplus1) % mod;
         // cout << "S4::" << s4 << endl;
        s4 = ((s4 + temp)/24)%mod;
        // cout << "S4::" << s4 << endl;






       	// //s3
        // s3 = ((n_pow_2_plus_n % mod)  * (nplus1 % mod)) % mod;
        // // cout << "s3 : " << s3 << endl;
        // s3 = (s3 * (twonplus1%mod) ) % mod;
        // s3 = (s3 / 6) % mod;
        // // cout << "s3 : " << s3 << endl;
        // s3 = s3 -  (modexp((n_pow_2_plus_n),2, mod)/4) % mod;
        // cout << "s3 : " << s3 << endl;
        // long long  temp = (((n-1)%mod * (n+2)%mod)%mod) / 2;
        // s3 = (s3 % mod  * temp % mod ) % mod;


       	// cout << (s3+s1)%mod << endl;
       	cout << s4 << endl;
        cout << s2 << endl;


    }
}