#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;
struct Node{
    Node *prev, *next;
    int key, val;
    Node(){}
    Node(int key, int val){
        this->val = val;
        this->key = key;
    }
};
class Solution {
public:
    unordered_map<int, Node*> mp;
    int MAX, cnt;
    Node* fp = new Node(-1, -1), *fl = new Node(-1, -1);
    vector<int> LRU(vector<vector<int>>& operators, int k) {
        MAX = k;
        fp->next = fl, fl->prev = fp;
        vector<int> ans;
        for(vector<int>& op : operators){
            if(op.size() == 3) set(op[1], op[2]);
            else ans.push_back(get(op[1]));
        }
        return ans; 
    }
    int get(int key){
        if(mp.count(key)){
            moveToHead(key);
            return mp[key]->val;
        }else return -1;
        
    }
    void set(int key, int value){
        if(mp.count(key)){
            mp[key]->val=value;
            moveToHead(key);
        }else{
            if((int)mp.size() == MAX) del(fl->prev->key);
            add(key, value);
        }
    }
    
    
    void moveToHead(int key){
        int value = mp[key]->val;
        del(key);
        add(key, value);
    }
    
    void del(int key){
        auto toDel = mp[key];
        toDel->prev->next = toDel->next;
        toDel->next->prev = toDel->prev;
        mp.erase(key);
    }
    
    void add(int key, int val){
        Node* toAdd = new Node(key, val);
        fp->next->prev = toAdd;
        toAdd->next=fp->next;
        toAdd->prev=fp;
        fp->next=toAdd;
        mp[key] = toAdd;
    }
};

int main(){
    vector<int> dp={1,2,3};
    // Solution s = Solution();
    // s.MAX = 1;
    // s.set(1,1);
    // cout << dp[0] << dp[1] << dp[2];
    // cout << s.get(1);
    return 0;

}