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
    int findNthDigit(int n) {
    	int st = 9, len = 1,idx, cur;
    	if(n <= 9) return n;
    	while(n > st){
    		n -= st;
    		st *= 10;
    		len++;
    	}
    	// cout << st << endl;
    	// cerr << " n : " << n << endl;
    	idx = ceil(1.0 * n / len);
    	cur = pow(10, len-1) + idx - 1;
    	// cout << "idx : "<< idx << endl << "cur" << cur << endl << "len" <<  len << endl;
    	string curS = to_string(cur);
    	return (int)(curS[n - (idx-1)*len - 1] - '0');
    }
};
int main(int argc, char * argv[]){

	Solution ss = Solution();
	// map<int,vector<int>> mp;
	// string s = "";
	// for(int i = 1; i <= 100; i++){
	// 	s = s + to_string(i);

	// }
	// for(int i = 0 ;i  < s.size(); i++) mp[s[i]-'0'].push_back(i);
	// for(int i = 0; i <= 9; i++){
	// 	for(auto it : mp[i]){
	// 		cout << it << " ";

	// 	}
	// 	cout<< endl;
	// }
	// cout << s;
	/* code */
	cout << ss.findNthDigit(300);


    return 0;
}