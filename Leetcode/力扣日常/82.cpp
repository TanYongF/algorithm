//https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii/
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


class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *move = head, *cur = head ;
        while(move != nullptr){
        	while(move->val == cur->val) move = move->next;
        	cur -> next = move;
        	cur = move;
        } 
        return head;
        

    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}