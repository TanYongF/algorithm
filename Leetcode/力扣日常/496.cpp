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
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    	stack<int> sk;
    	unordered_map<int,int> mp;
    	sk.push(INT_MAX);
    	for(int i = 0; i < nums2.size(); i++){
    		while(nums2[i] > sk.top()){
    			mp[sk.top()] = nums2[i];
    			sk.pop();
    		}
    		sk.push(nums2[i]);
    	}
    	int size = nums1.size();
    	vector<int> ans(size , -1);
    	for(int i = 0; i < nums1.size(); i++)
    		if(mp.find(nums1[i]) != mp.end())
    			ans[i] = mp[nums1[i]];
    	return ans;
    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}