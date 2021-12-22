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
  ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode  pre, cur, tem;
    ListNode* reverseList(ListNode* head) {
        if(not head) return head;
        pre = head;
        cur = pre -> next;
        while(cur){
        	tem = cur -> next;
        	cur -> next = pre;
        	pre = cur;
        	cur = tem;
        }
        return cur;
    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}