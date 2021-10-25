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
#include <bitset>
#include <list>
using namespace std;

typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
typedef long long ll;
class Solution {
public:
	int maxIdx = 2;
	ll p[35];
	void init(ll divisor){
		p[0] = 0,p[1] = divisor;	
		while(p[maxIdx-1] <= INT_MAX and p[maxIdx-1] > 0){
			p[maxIdx] = p[maxIdx-1] + p[maxIdx-1];
			maxIdx++;
		}
		maxIdx = max(1, maxIdx-2);
	}
    int divide(ll dividend, ll divisor) {
    	long long ans= 0;
    	int flag = dividend * divisor < 0 ? -1 : 1;
    	divisor = abs(divisor), dividend = abs(dividend);
    	init(divisor);
    	if(dividend == 0) return 0; 
    	else if(divisor == 1) ans = dividend;
    	else{
	    	while(maxIdx >= 1 and dividend >= divisor){
	    		while(dividend >= p[maxIdx]){
	    			dividend -= p[maxIdx];
	    			ans += (1 << (maxIdx-1));
	    		}
	    		maxIdx--;
	    	}
    	}
    	long long ret = flag * ans;
    	if(flag == 1) return ret > INT_MAX ? INT_MAX : ret;
    	if(flag == -1) return ret < INT_MIN ? INT_MIN : ret;
    	return 0;
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	cout << s.divide(-2147483648,-2147483648);
	/* code */


    return 0;
}