//https://leetcode-cn.com/problems/nth-magical-number/
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
	int gcd(int a, int b){
		if(b == 0) return a;
		return gcd(b, a % b);  
	}
    int nthMagicalNumber(int n, int a, int b) {
    	int mod = 1e9+7;
    	long long L = 1, R = 1e15;
    	long long ans, size, lcm;
    	while(L <= R){
    		long long mid = (L + R) >> 1;
    		size = mid / a + mid / b - mid / (a * b / gcd(a,b));
    		if(size == n &&  (mid % a == 0 || mid % b == 0)) return mid % mod;
    		else if(size >= n) R = mid - 1;
    		else L = mid + 1;
    	}
    	return 0;

    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	cout << s.gcd(2,4);
	cout << s.nthMagicalNumber(3,2,3);
	/* code */


    return 0;
}