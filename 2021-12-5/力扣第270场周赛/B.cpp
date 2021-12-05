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
    ListNode* deleteMiddle(ListNode* head) {
    	vector<ListNode*> v;
    	ListNode* cur= head;
    	while(cur){
    		v.push_back(cur);
    		cur = cur -> next;
    	}
    	ListNode* ans = new ListNode();
    	ListNode* pre = ans;
    	if(v.size() == 1) return nullptr;
    	int del = v.size() / 2;
    	for(int i = 0; i < v.size(); i++){
    		if(i == del) continue;
    		pre->next = v[i];
    		pre = v[i];
    	}
    	return ans->next;
       
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}