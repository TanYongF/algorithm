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

struct DLinkNode{
	DLinkNode* pre, *next;
	int val = -1;
	DLinkNode(){}
	DLinkNode(int _val){
		_val = val;
	}
};
class LRUCache {
public:
	unordered_map<int, DLinkNode*> mp;
	DLinkNode *fakePre = new DLinkNode(), *fakeLast = new DLinkNode();

	int capacity, csize = 0;
    LRUCache(int _capacity) {
    	capacity = _capacity;
    	fakePre->next = fakeLast;
    	fakeLast->next = fakePre;
    }
    
    int get(int key) {
    	if(not mp.count(key)) return -1;
    	moveToHead(mp[key]);
    	return mp[key]->val;
    }
    
    void put(int key, int value) {
    	if(mp.count(key)){
    		removeVal(mp[key]);
    	}else{
	    	csize++;
	    	while(csize > capacity){
	    		removeLast();
	    		csize--;
	    	}
    	}
		DLinkNode* newNode = new DLinkNode(value);
		addToHead(newNode);
		mp[key] = newNode;
    }
    void moveToHead(DLinkNode* node){
    	removeVal(node);
    	addToHead(node);
    }
    void addToHead(DLinkNode* node){
    	DLinkNode* first = fakePre->next;
    	fakePre->next = node;
    	node->next = first;
    	if(first) first->pre = node;
    }
    void removeLast(){
    	DLinkNode* item = fakeLast->pre;
    	if(item == fakePre) return;
    	item->pre->next = fakeLast;
    	fakeLast->pre = item->pre;
    	free(item);
    }
    void removeVal(DLinkNode* node){
    	node->pre->next= node->next;
    	node->next->pre = node->pre;
    	free(node);
    }
};

int main(int argc, char * argv[]){

	// Solution s = Solution();
	/* code */


    return 0;
}