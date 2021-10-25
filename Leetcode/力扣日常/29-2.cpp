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
class Solution {
public:
	long long mul(long long a, long long k){
		if(k == 0) return 1;
		long long ans = 0;
		while(k > 0){
			if((k&1)==1) ans += a;
			k >>= 1;
			a += a; 
		}
		// cout << ans << endl;
		return ans;
	}
    int divide(int dividend, int divisor) {
    	long long a = dividend, b = divisor;
    	// cout << a << b;
    	if(a == 0) return 0;
    	long long ans = 0;
    	int flag = 1;
    	if((a>0&&b>0)||(a<0&&b<0)) flag = 1;
    	else flag = -1;
    	a = abs(a);
    	b = abs(b);
    	// cout << a <<"  " << b << endl;
    	long long L = 0, R = a;
    	while(L <= R){
    		long long mid = (L + R + 1) >> 1;
    		long long  cur = mul(b, mid);
    		if(cur ==  a){
    			ans = mid;
    			break;
    		}else if(cur > a){
    			R = mid - 1;
    		}else {
    			ans = mid;
    			L = mid + 1;
    		}
    	}
    	// cout << L << endl;
    	if(flag == 1) return ans > INT_MAX ? INT_MAX : ans * flag;
    	else if(flag == -1) return ans > INT_MAX ? INT_MIN : ans * flag;
    	return 0;

    }
};

int main(int argc, char * argv[]){
		Solution s = Solution();
	cout << s.divide(2147483648,2147483648) << endl;
	// cout << s.divide(-21,-1) << endl;
	// 	// cout << ""
	cout << s.divide(2147483647,1) << endl;
	cout << s.divide(-2147483648,2147483648) << endl;


	/* code */


    return 0;
}