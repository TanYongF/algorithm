//https://leetcode-cn.com/problems/rotate-list/
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
    ListNode* rotateRight(ListNode* head, int k) {
    	if(!head) return head;
    	int len = 0;
    	ListNode *cur = head, *end;
    	while(cur!=nullptr){
    		len++;
    		end = cur;
    		cur = cur->next;
    	}
    	end -> next = head;
    	int last = len - k % len;
    	if(last == len) return head;
    	cur = head;
    	while(last--){
    		cur = cur -> next;
    	}
    	return cur;
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}