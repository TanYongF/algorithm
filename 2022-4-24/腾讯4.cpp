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


class Solution {
public:
    ListNode* solve(vector<ListNode*>& a) {
    	unordered_map<int, int> mp;
    	vector<int> v;
    	//存储此节点和后继节点的值，key：当前节点的值 value:后继节点的值
    	for(auto nodes : a){
    		ListNode* cur = nodes;
    		while(cur){
    			if(cur->next) mp[cur->val] = cur->next->val;
    			cur = cur->next;
    		}
    	}

    	//转换为数组
    	int cur = (mp.begin()->first), start = cur;
    	v.push_back(cur);
    	cur = mp[cur];
    	while(cur != start){
    		v.push_back(cur);
    		cur = mp[cur];
    	}

    	//找到最小元素下标
    	int len = v.size();
    	auto minn = min_element(v.begin(),v.end());
    	int startIdx = std::distance(std::begin(v), minn);

    	//查看前驱或者后继，如果前驱小，那么inv=-1， 如果后继小，那么inv = 1
    	int inv = 1;
    	if(v[(startIdx+1)%len] > v[(startIdx-1+len)%len]) inv = -1; 

    	//构造链表
    	ListNode* fake = new ListNode(-1), *curr = fake;
    	for(int i = 0 ; i < len; i++){
    		curr->next = new ListNode(v[(startIdx + inv + len) % len]);
    		curr = curr->next; 
    	}
    	return fake->next;
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();


	/* code */


    return 0;
}