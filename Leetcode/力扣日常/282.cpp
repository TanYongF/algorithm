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
	int len, target;
	string num;
	vector<string> ans;
    vector<string> addOperators(string num, int target) {
    	len = num.length();
    	this->num =num, this->target = target;
    	string s(1,num[0]);
    	backTracing(s, num[0]-'0', 1, num[0]-'0');
    	for(auto it : ans) cout << it << " ";
    	return ans;


    }
    void backTracing(string curStr, ll curRes, int curIdx, ll prev){
        cout << curStr << " " << curRes << endl;
    	if(curIdx == len){
    		if(curRes == target){
                cout << curStr << " " << curRes << " " << endl;
                ans.push_back(curStr);
                
            }
    		return;
    	}
        ll cur;

    	backTracing(curStr + "+" + num[curIdx], curRes + (num[curIdx] - '0'), curIdx+1, (num[curIdx] - '0'));
    	backTracing(curStr + "-" + num[curIdx], curRes - (num[curIdx] - '0'), curIdx+1, -(num[curIdx] - '0'));
        if(prev != 0){
            int temp = curStr.length() - 1;
            ll base = 0 , w = 1;
            while(temp >= 0 and curStr[temp] <= '9' and curStr[temp] >= '0'){
                base += w * (curStr[temp]- '0');
                cout << 1;
                w *= 10;
                temp--;
            }
            cout << prev << base;
            base = prev / base;
            // cout << base;
            cur = curRes - prev + prev * 10 + (num[curIdx]-'0') * base;
            cout << cur;
            backTracing(curStr + num[curIdx], cur, curIdx + 1, prev * 10 + (num[curIdx] - '0') * base);
        }
    	cur = curRes - prev + prev * (num[curIdx] - '0');
    	backTracing(curStr + "*" + num[curIdx], cur , curIdx+1, prev * (num[curIdx] - '0'));

    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	s.addOperators("3456237490",9191);
	/* code */


    return 0;
}