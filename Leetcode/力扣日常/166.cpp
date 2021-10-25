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
typedef long long ll;
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

class Solution {
public:
    string fractionToDecimal(long  numerator, long denominator) {
        string ans = "";
        if(numerator % denominator == 0) return to_string(numerator / denominator);
        if(numerator * denominator < 0) ans += '-';
        numerator = abs(numerator), denominator = abs(denominator);
        ans = ans + to_string(numerator / denominator) + '.';
        numerator %= denominator;
        unordered_map<long,int> mp;
        while(numerator != 0){
            mp[numerator] = ans.length();
            numerator *= 10;
            ans = ans + to_string(numerator / denominator);
            numerator %= denominator;
            if(mp.count(numerator)){
                int idx = mp[numerator];
                return ans.substr(0, idx) + '(' + ans.substr(idx, ans.length() - idx + 1) + ')';
            }
        }
        return ans;

    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	cout << s.fractionToDecimal(1,3);
	/* code */


    return 0;
}