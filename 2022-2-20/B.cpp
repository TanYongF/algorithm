#include <bits/stdc++.h>
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
  struct ListNode {
      int val;
      ListNode *next;
    ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
      ListNode *fake = head;
      ListNode *cur = head->next, *last = head;
      while(cur){
        last = cur;
        int curnum = 0;
        while(last->val != 0){
          curnum += last->val;
          last = last->next;
        }
        fake->next = new ListNode(curnum);
        fake=fake->next;
        cur = last -> next;
      }
      return fake->next;
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}