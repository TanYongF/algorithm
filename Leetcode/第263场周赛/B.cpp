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
#include <bitset>
#include <list>
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
class Bank {
public:
	map<int,long long> mp;
    Bank(vector<long long>& balance) {
    	int idx =1;
    	for(auto b : balance){
    		mp[idx++] = b;
    	}
    }
    
    bool transfer(int account1, int account2, long long money) {
    	if(mp.find(account1) != mp.end() and mp.find(account2) != mp.end()){
    		if(mp[account1] < money) return false;
    		mp[account1] -= money;
    		mp[account2] += money;
    		return true;
    	}
    	return false;


    }
    
    bool deposit(int account, long long money) {
    	if(mp.find(account) == mp.end()) return false;
    	mp[account] += money;
    	return true;

    }
    
    bool withdraw(int account, long long money) {
		if(mp.find(account) == mp.end()) return false;
		if(mp[account] < money) return false;
    	mp[account] -= money;

    }
};

int main(int argc, char * argv[]){

	// Solution s = Solution();
	/* code */


    return 0;
}