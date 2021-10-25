//https://leetcode-cn.com/problems/reverse-linked-list-ii/
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
    	if(right - left == 0) return head;
    	ListNode *pre = head, *last = head, *cur = head, *start, *end;
    	for(int i = 1; i <= right; i++){
    		if(i == left-1)  pre = cur;
    		else if(i == right) end = cur;
    		cur = cur -> next; 
    	}
    	last = end->next;
    	start = pre->next;
    	reverse(start, start->next, end);
    	start->next = last;
    	pre->next = end;
    	return head;

    }
    void reverse(ListNode *pre, ListNode *after, ListNode * end){
    	if(pre == end) return;
    	reverse(after, after->next,end);
    	pre->next = NULL;
    	after->next = pre;

    }

};

int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}