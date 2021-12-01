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
class Solution {
public:
    int m, n;
    int cnt = 0;
    vector<int> ans;
    unordered_map<int,int> mp;
    Solution(int m, int n) {
    	this->m = m, this->n = n; 
    	cnt = m * n;
    }   
    
    vector<int> flip() {
    	int rd = rand()%cnt;
    	cnt--;
    	if(mp.find(rd) == mp.end()) mp[rd] = rd;
    	ans = {mp[rd]/n, mp[rd] % n};
    	mp[rd] = mp.find(cnt) == mp.end() ? cnt : mp[cnt];
    	return ans;
    }
    
    void reset() {
    	cnt = m * n;
    	mp.clear();
    }
};


int main(int argc, char * argv[]){

	Solution s = Solution(10000,10000);
	vector<int> a = s.flip();
	cout << a[0] << a[1] << endl;
	a = s.flip();
	cout << a[0] << a[1] << endl;
		a = s.flip();
	cout << a[0] << a[1] << endl;
		a = s.flip();
	cout << a[0] << a[1] << endl;
	/* code */


    return 0;
}