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
#include <bitset>
#include <vector>
#include <iostream>
#include <list>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;

// class Solution {
// public:
//     int getSum(int a, int b) {
//     	while(b != 0){
//     		int carry = (a & b) << 1;
//     		a = a ^ b;
//     		b = carry;
//     	}
//     	return a;

//     }
// };

class Solution {
public:
    int getSum(int a, int b) {
    	// cout << a << b;
    	int t =0, ans = 0;
    	for(int i = 0; i < 32; i++){
    		int u1 = (a >> i) & 1, u2 = (b >> i) & 1;
    		cout << u1 << " " << u2 << endl;
    		if(u1 == 0 and u2 == 0) ans |= (t << i), t = 0;
    		else if(u1 == 1 and u2 == 1) ans |=  (t << i), t = 1;
    		else ans |= ( (t ^ (u1 | u2)));  	
    	}
    	return ans;

    }
};

int main(int argc, char * argv[]){

	// bitset<64> bit(-1);
	Solution s = Solution();
	cout << s.getSum(-1,-1);

	// cout << bit.to_string();
	/* code */


    return 0;
}