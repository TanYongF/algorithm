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
class Bitset {
public:
	vector<bool> data;
	int ones = 0, zero = 0, len; 
	bool flag = false;
	bool get(bool data){
		return (data ? 1 : 0) ^ (flag ? 1 : 0); 
	}
    Bitset(const int size) {
    	data= vector<bool>(size, false);
    	zero = size;
    	len = size;
    }
    
    void fix(int idx) {
    	if(not get(data[idx])) return;
    	data[idx] = 1;
    	zero--;
    	ones++;
    }
    
    void unfix(int idx) {
    	if(get(data[idx])) return;
    	data[idx] = 0;
    	zero++;
    	ones--;
    }
    
    void flip() {
    	flag = not flag;

    }
    
    bool all() {
    	return len == ones;
    }
    
    bool one() {
    	return ones >= 1;

    }
    
    int count() {
    	return ones;
    }
    
    string toString() {
    	string ans;
    	for(int i = 0; i < len; i++){
    		ans += data[i] ? '1' : '0'; 
    	}
    	return ans;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */
int main(int argc, char * argv[]){

	// Solution s = Solution();
	/* code */


    return 0;
}