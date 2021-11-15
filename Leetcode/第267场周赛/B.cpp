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
// struct ListNode {
//   int val;
//   ListNode *left;
//   ListNode *right;
//   ListNode() : val(0), left(nullptr), right(nullptr) {}
//   ListNode(int x) : val(x), left(nullptr), right(nullptr) {}
//   ListNode(int x, ListNode *left, ListNode *right) : val(x), left(left), right(right) {}
// };
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
	int len = 0;

    ListNode* reverseEvenLengthGroups(ListNode* head) {
        vector<ListNode*> vs;
    	vector<int> start;
        vs.push_back(head);
        ListNode *cur = head;
        while(head){
        	vs.push_back(cur);
        	cur = cur -> next;
        	len++;
        };
        cout << len << endl;
        if(len <= 2) return head;
        int last = 0;
        start.push_back(0);

        for(int i = 1; start[i-1] + i <= len; i++) start.push_back(start[i-1] + i);

        for(auto it : start) cout << it;

        int startLen = start.size();
    	if(start[startLen-1] != len) {
    		last = len - start[startLen-1];
    	}

        cur = head;
    	for(int i = 2; i <= startLen; i++){
    		if(start[i] % 2 == 0){
    			for(int j = start[i]; j > start[i-1]; j--){
    				cur->next=vs[j];
    				cur = cur -> next; 
    			}
    		}else{
    			for(int j = start[j-1] + 1; j <= start[j]; j++){
    				cur->next = vs[j];
    				cur = cur->next;
    			}
    		}
    	}
    	if(last != 0){
    		if(last % 2 == 0){
    			for(int j = len; j > start[startLen-1]; j--){
    				cur->next=vs[j];
    				cur = cur -> next; 
    			}
    		}else{
    			for(int j = start[startLen-1]; j <= len; j++){
    				cur->next = vs[j];
    				cur = cur->next;
    			}
    		}
    	}
    	return head;
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}