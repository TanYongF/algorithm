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
class LRUCache {
public:
    struct DLinkedNode{
        int key;
        int value;
        DLinkedNode *prev = nullptr, *next = nullptr;
        DLinkedNode(){}
        DLinkedNode(int _key, int _val){
            this->value = _val;
            this->key = _key;
        }
    };
    unordered_map<int, DLinkedNode*> mp;
    int capacity, nums = 0;
    DLinkedNode *fakeHead = new DLinkedNode(-1, -1);
    DLinkedNode *fakeTail = new DLinkedNode(-1, -1);
    LRUCache(int _capacity) {
        this->capacity = _capacity;
    }
    
    int get(int key) {
        if(not mp.count(key)) return -1;
        addToHead(mp[key]);
        return mp[key]->value;
    }
    
    void put(int key, int value) {
        if(not mp.count(key)){
            DLinkedNode *node = new DLinkedNode(key, value);
            addToHead(node);
            mp[key] = node;
            if(mp.size() > capacity){
                int removeKey = fakeTail->prev->key;
                removeNode(mp[key]);
                mp.remove(removeKey);
                free(mp[key])
            }
        }else{
            moveToHead(mp[key]);
        }

    }

    void removeNode(DLinkedNode* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;    
    }
    void addToHead(DLinkedNode* node){
        node->next = fakeHead->next;
        fakeHead->next->prev = node;
        node->prev = fakeHead;
        fakeHead->next = node;
    }

    void moveToHead(DLinkedNode* node){
        removeNode(node);
        addToHead(node);
    }

    
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}