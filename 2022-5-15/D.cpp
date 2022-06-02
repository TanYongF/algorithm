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


class CountIntervals {
public:
	int nums = 0;
    set<pair<int,int>>rightLeft;
    void addRange(int left, int right) {
        auto it=rightLeft.lower_bound({left,0});
        while(it!=rightLeft.end()&&right>=it->second){
            left=min(left,it->second);
            right=max(right,it->first);
            nums -= (it->first - it->second + 1);
            it=rightLeft.erase(it);

        }
        rightLeft.emplace(right,left);
        nums += (right - left + 1);
    }
    CountIntervals() {

    }
    
    void add(int left, int right) {
    	addRange(left, right);
    }
    
    int count() {
    	return nums;
    }
};


int main(int argc, char * argv[]){

	// Solution s = Solution();
    string s = "fafaF";
    string s1 = "tan";
    return s > s1;
    	/* code */


    return 0;
}