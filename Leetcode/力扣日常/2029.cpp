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

class Solution {
public:
	int size;
	bool check(vector<int> &item, int first){
		if(!item[first]) return false;
		int sum = 1 + item[0];
		int fs = item[1], ss = item[2];
		if(first == 1) fs--;
		else ss--;
		// cout << fs << " " << ss << endl;
		int minx = min(fs,ss);
		sum += 2 * minx;
		fs -= minx;
		ss -= minx;
		if((first == 1 and fs) or (first == 2 and ss)) sum++;
		// if(fs) sum++;
		// cout << sum << endl;
		return sum % 2 == 1 && sum != size;  
	}
    bool stoneGameIX(vector<int>& stones) {
    	size = stones.size();
    	vector<int> items(3, 0);
    	for(auto it : stones) items[it%3]++;
    	// for(auto it : items) cout << it << " ";
    	// 	cout << endl;
    	if(not items[2] and not items[1]) return false;
    	return check(items, 1) || check(items, 2);
    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	vector<int> test = {2,8,6,13,15,11,3,7};
	cout << s.stoneGameIX(test);
	/* code */


    return 0;
}