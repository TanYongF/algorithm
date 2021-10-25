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

// class Solution {
// public:
//     int findComplement(int num) {
//         long long ans = 0;
//         int idx = 0;
//         while(num){
//             ans |=  (!(num & 1)) << idx;
//             num >>= 1;
//             idx++;
//             cout << num << " " << ans << endl;

//         }
//         return ans ;

//     }
// };
class Solution {
public:
    int findComplement(int num) {
        int highBit =0, ans= 0;
        for(int i = 0; i <= 30; i++){
        	if(num & (1 << i)) highBit = i;
        }
        ans =  highBit == 30 ?  0x7fffffff : ((1 << (highBit+1)) - 1);
        
        return ans ^ num;

    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	cout << s.findComplement(3);
	/* code */


    return 0;
}