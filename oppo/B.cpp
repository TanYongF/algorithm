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
	struct ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};
 
bool cmp(ListNode* n1, ListNode *n2){
	return n1->val < n2->val;
}
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param node1 ListNode类 
     * @param node2 ListNode类 
     * @return ListNode类
     */
    ListNode* combineTwoDisorderNodeToOrder(ListNode* node1, ListNode* node2) {
        // write code here
        ListNode* fake = new ListNode(-1), *cur = fake;
        vector<ListNode*> v;
        while(node1) {v.push_back(node1); node1 = node1->next;}
        while(node2) {v.push_back(node2); node2 = node2->next;}
        sort(v.begin(), v.end(), cmp);
        for(int i = 0, n = v.size(); i < n - 1; i++){
        	v[i]->next = v[i+1];
        }
        return v[0];
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}