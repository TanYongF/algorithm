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
    int timeRequiredToBuy(vector<int>& tickets, int k) {
    	queue<int> q;
    	int ans = 0;
    	int len = tickets.size();
    	while(tickets[k] != 0){
    		for(int i = 0; i < len; i++){
    			if(tickets[i] > 0) {
    				tickets[i]--;
    				ans++;
    			}
    		}
    	}
    	return ans;
        
    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}