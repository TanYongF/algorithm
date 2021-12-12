#include <bits/stdc++.h>
#include<bits/extc++.h>
using namespace __gnu_pbds;
// using namespace std;
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


bool cmp(const pair<string,int>& p1, const pair<string,int>& p2){
	if(p1.second != p2.second){
		return p1.second > p2.second;
	}else{
		return p1.first < p2.first;
	}
}
class SORTracker {
public:
    typedef pair<int,string> pii;
    tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update> tr;
    int c=0;
    SORTracker() {
        
    }
    
    void add(string a, int b) {
        tr.insert({-b,a});
    }
    
    string get() {
        ++c;
        return tr.find_by_order(c-1)->second;
    }
};


/**
 * Your SORTracker object will be instantiated and called as such:
 * SORTracker* obj = new SORTracker();
 * obj->add(name,score);
 * string param_2 = obj->get();
 */
int main(int argc, char * argv[]){
	cout << ("tanyongfeng" < "fa");
	// Solution s = Solution();
	return 0;
	/* code */


    // return 0;
}