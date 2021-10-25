//https://leetcode-cn.com/problems/ugly-number-iii/
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
#include <climits>
#include <vector>
#include <iostream>
#include <list>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;

class Solution {
public:
	int gcd(long long a, long long b){
		if(b == 0) return a;
		return gcd(b, a % b);
	}
    int nthUglyNumber(int n, int a, int b, int c) {
    	long long lcm1 = (long long)a*b/gcd(a,b);
    	long long lcm2 = (long long)a*c/gcd(a,c);
    	long long lcm3 = (long long)c*b/gcd(c,b);
    	long long lcm4 = (long long)lcm1*c/gcd(lcm1, c);
    	long long L = 1, R = 1e10, size;
    	while(L <= R){
    		long long mid = (L + R) >> 1;
    		size = mid/a + mid/b + mid/c - mid/lcm1 - mid/lcm2 - mid/lcm3 + mid/lcm4;
    		if(size == n &&  (mid % a == 0 || mid % b == 0 || mid % c == 0)) return mid;
    		else if(size >= n) R = mid - 1;
    		else L = mid + 1;
    	}
    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}