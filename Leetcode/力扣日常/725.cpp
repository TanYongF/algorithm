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

  struct ListNode {
      int val;
      ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len = 0;
        vector<ListNode*> ans(k);
        ListNode *cur = head , *pre = head;
        for(; cur; cur = cur->next, len++);
        int a = len / k, b = len % k;
    	int curLen = 0;
        int ansI = 0;
        while(!head){
    		ans[ansI++] = head;
    		pre = head;
    		if(b > 0) curLen = a, b--;
    		else curLen = a-1;
        	while(curLen--)	pre = pre->next;
        	head = pre->next;
        	pre->next = nullptr;
        }
        return ans;
    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}