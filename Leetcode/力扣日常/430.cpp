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


class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

class Solution {
public:
	Node *ans;
	// queue<Node *> q;
    Node* flatten(Node* head) {
    	ans = head;
    	while(!head){
    		if(!head->child) head = head -> next;
    		else{
    			Node *temp = head->next;
    			Node *child = head->child;
    			child -> prev = head;
    			head -> next = child;
    			Node *last = child;
    			while(last->next) last = last -> next;
    			temp->prev = last;
    			last->next = temp;
    			head = head -> next;
    		}
    	}
    	return ans;
 

        
    }
};



// class Solution {
// public:
// 	vector<Node*> ans;
//     Node* flatten(Node* head) {
//     	int len = ans.size();
//     	for(int i = 1; i < len-1; i++) ans[i]->child = nullptr, ans[i]->prev = ans[i-1], ans[i]->next = ans[i+1];
        
//     }
// 	void dfs(Node *node){
// 		if(!node) return;
// 		ans.push_back(node);
// 		dfs(node -> child);
// 		dfs(node -> next);


// 	}
// };
int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}