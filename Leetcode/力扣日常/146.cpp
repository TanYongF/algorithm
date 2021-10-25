#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <string>
#include <cstring>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <ctime>
#include <climits>
#include <vector>
#include <iostream>
#include <fstream>
#include <list>
#include <iomanip>
#include <numeric>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;

typedef pair<int,int> P;
struct DLinkedNode{
	DLinkedNode *pre, *next;
	int key, value;
    DLinkedNode(): key(0), value(0), pre(nullptr), next(nullptr) {}
    DLinkedNode(int _key, int _value): key(_key), value(_value), pre(nullptr), next(nullptr) {}
};
class LRUCache {
public:
	unordered_map<int, DLinkedNode*> mp;
	int curSize = 0, maxcapacity;
	DLinkedNode *head, *tail;
    LRUCache(int capacity){
    	maxcapacity = capacity;  
    	head = new DLinkedNode();
    	tail = new DLinkedNode();
    	tail -> pre = head;
    	head -> next = tail;
    }
    
    int get(int key) {
    	if(mp.find(key) == mp.end()) return -1;
    	// cout << " ----";
    	int ret = mp[key]->value;
    	moveToHead(mp[key]);
    	return ret;
    }
    
    void put(int key, int value) {
    	// cout << key << " " << value << endl;
    	// cout << curSize << endl;
    	if(mp.find(key) == mp.end()){
    		if(maxcapacity == curSize){
    			DLinkedNode* nodeRemove = removeTail();
    			mp.erase(mp.find(nodeRemove->key));
    			delete nodeRemove;
    			curSize--;
    		}
			DLinkedNode *nodeToAdd = new DLinkedNode(key, value);
			addToHead(nodeToAdd);
			mp[key] = nodeToAdd;
			curSize++;
    	}else{
    		DLinkedNode *nodeToChange = mp[key];
    		nodeToChange->value = value;
    		moveToHead(nodeToChange);
    	}
    }
    void addToHead(DLinkedNode *node){
    	node->pre = head;
    	node->next = head->next;
    	head->next->pre = node;
    	head->next = node;
    }
    void removeNode(DLinkedNode *node){
    	node->pre->next = node->next;
    	node->next->pre = node->pre;
    }
    void moveToHead(DLinkedNode *node){
    	// cout << 1;
    	removeNode(node);

    	addToHead(node);
    }
    DLinkedNode* removeTail(){
    	DLinkedNode *node = tail->pre;
    	removeNode(node);
    	return node;
    }
};

int main(int argc, char * argv[]){

	// Solution s = Solution();
	// DLinkedNode d = DLinkedNode(1,3);	
	// cout << d.value;

	LRUCache lc =  LRUCache(2);
	// cout << 1;
	lc.put(2,2);
	lc.put(3,3);
	lc.put(2,3);
	cout << lc.get(2);
	
	// cout << lc.dq.size() << endl;
	// cout << lc.get(2);
	// cout << lc.dq.size() << endl;

	/* code */


    return 0;
}