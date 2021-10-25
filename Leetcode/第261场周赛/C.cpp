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
	// int sg[100];
	// bool hasVisted[100];
	// vector<int> stones;
	// int getSG(int haveTake){
	// 	if(sg[x] != -1) return sg[x];
	// 	unordered_set<int> st;
	// 	for(int i = 0; i < stones; i++){
	// 		if(hasVisted[i]) continue;
	// 		hasVisted[i] = true;
	// 		st.insert(getSG(haveTake + stones[i]));
	// 		hasVisted[i] = false;
	// 	}
	// 	for(int i = 0; ; i++){
	// 		if(!count(i)) return sg[x]
	// 	}
	// }

    bool stoneGameIX(vector<int>& stones) {
    	int sum = 0;
    	for(auto it : stones) sum += it;
    	int size = stones.size();
    	if(size % 3 != 0) return false;
    	else{
    		if(size % 2 == 0) return true;
    		else return false;
    	}
    	return false;
    }
}; 

int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}