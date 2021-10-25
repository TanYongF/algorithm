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
	int maxIndex = 1;
	long long item[41];
	long long num[41];
	void init(long long divisor){
		item[1] = divisor;
		num[1] = 1;
		for(int i = 2; i <= 40; i++){
			item[i] = item[i-1]<<1;
			num[i] = num[i-1]<<1;
			maxIndex++;
			if(item[i] > INT_MAX) break;
		}
	}
    int divide(int dividend, int divisor) {
    	long long  divisor2 = (long long)divisor;
    	long long  dividend2 = (long long)dividend;
    	init(abs(divisor2));
    	// cout << maxIndex;
    	int flag = 1;
    	long long ans = 0;
    	if(dividend2 == 0) return 0;
    	if((dividend2 > 0 && divisor2 > 0) || (dividend2 < 0 && divisor2 < 0)) flag = 1;
    	else flag = -1;
    	dividend2 = abs(dividend2);
    	divisor2  = abs(divisor2);
    	int index = maxIndex;
    	while(dividend2 >= divisor2){
    		while(index > 0 && item[index] <= dividend2){
    			// cout << item[index] << endl;
    			ans += num[index];
    			dividend2 -= item[index];
    		}
    		index--;
    	}
    	if(flag == 1) return ans > INT_MAX ? INT_MAX : ans * flag;
    	else if(flag == -1) return ans > INT_MAX ? INT_MIN : ans * flag;
    	return 0;
    }
};
int main(int argc, char * argv[]){
	Solution s = Solution();
	// cout << s.divide(-2147483648,-2147483648) << endl;
	cout << s.divide(-2147483648,-1) << endl;
	// cout << s.divide(-2147483648,1) << endl;
	// cout << s.divide(-2147483648,2147483648) << endl;

	/* code */


    return 0;
}