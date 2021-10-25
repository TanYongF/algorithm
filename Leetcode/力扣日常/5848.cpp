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

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;

struct TNode {
 int val;
 bool locked;
 int loockedid;
 TNode *left;
TNode *right;
 TNode(int x) : val(x), locked(false),loockedid(-1), left(NULL), right(NULL) {}
};


class LockingTree {
public:
	vector<TNode*> vs;
	TNode *head;
	bool chilrd, fatherlo;
	vector<int> parent;
    LockingTree(vector<int>& parent) {
    	this->parent = parent;
    	vs  = vector<TNode*>(2010);
    	for(int i =  0; i < parent.size(); i++) vs[i] = new TNode(i);
    	for(int i = 0; i < parent.size(); i++){
    		if(parent[i] == -1){ head = vs[i]; continue;}
    		if(!(vs[parent[i]]->left)) vs[parent[i]]->left = vs[i];
    		else vs[parent[i]]->right = vs[i];
    	}
    }
    

    bool lock(int num, int user) {
    	if(vs[num]->locked) return false;
    	vs[num]->locked = true;
    	vs[num]->loockedid = user;
    	return true;
    }
    
    bool unlock(int num, int user) {
    	if(vs[num]->locked && vs[num]->loockedid == user) {
    		vs[num]->locked = false;
    		vs[num]->loockedid = -1;
    		return true;
    	}
    	return false;
    }
    
    bool upgrade(int num, int user) {
    	if(vs[num]->locked) return false;
    	chilrd = false;
    	fatherlo = true;
    	dfs(vs[num]);
    	if(!chilrd) return false;
    	int fatherNode = num;
    	while(fatherNode != -1){
    		if(vs[fatherNode]->locked) return false;
    		fatherNode = parent[fatherNode];
    	}
    	if(fatherlo){
    		unlockedchild(vs[num]);
    		vs[num]->locked = true;
    		vs[num]->loockedid =user;
    	}
    	return fatherlo;

    }
    void dfs(TNode *head){
    	if(!head || chilrd) return;
    	dfs(head->left);
    	if(head->locked){
    		chilrd = true;
    		return;
    	}
    	if(!chilrd) dfs(head->right);
    	return;
    }
    void unlockedchild(TNode *head){
    	if(!head) return;
    	unlockedchild(head->left);
    	head->locked = false;
     head->loockedid=-1;
    	unlockedchild(head->right);

    }
};

int main(int argc, char * argv[]){

	// Solution s = Solution();/*/
	vector<int> t = {-1, 0, 0, 1, 1, 2, 2};
	LockingTree  s = LockingTree(t);
	
	/* code */


    return 0;
}