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
    int countDigitOne(int n) {
    	if(n == 0) return 0;
        int ans = 0;
        ll DN = 1; 
        int lastNum = 0;
        while(n / DN != 0){
        	int curbit = n / DN % 10;
        	ll D = DN * 10;
        	if(n % D == 0) ans += n/10;
        	else if(curbit == 0) ans += (n/D)*D/10;
        	else if(curbit >= 2) ans += ((n/D)+1)*D/10;
        	else if(curbit == 1) ans += (n/D)*D/10 + lastNum + 1;
        	lastNum += curbit * DN;
            // cout << D << " : " << ans << " lastNum:" << lastNum<<endl; 
            DN *= 10;
        }
        return ans;
    }
};
int main(int argc, char * argv[]){
	Solution s= Solution();
	cout << s.countDigitOne(1000000000);


	/* code */


    return 0;
}