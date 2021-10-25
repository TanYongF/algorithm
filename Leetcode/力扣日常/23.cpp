//https://leetcode-cn.com/problems/merge-k-sorted-lists/
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
  struct Status{
  	int val;
  	ListNode *ptr;
  	bool operator < (const Status &rs) const{
  		return val > rs. val;
  	}
  };

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
    	priority_queue<Status> pq;
    	for(auto list : lists){
    		while(list) pq.push({list->val, list});
    	}
    	ListNode *head = new ListNode();
    	ListNode *tail = head;
    	while(!pq.empty()){
    		Status st = pq.top();
    		tail->next = st.ptr;
    		tail = tail->next;
    		if(st.ptr -> next) pq.push({st.ptr->next->val, st.ptr->next});
    	}
    	return head->next;

    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}