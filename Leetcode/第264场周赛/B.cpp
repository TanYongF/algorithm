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
	const int MAXN  = 1e7 + 10;
	set<int> st;
	vector<vector<int>> vs;
	vector<int> temp;
    vector< vector<int> > result;
    vector<int> path;
    int nextBeautifulNumber(int n) {
    	dfs(0,1);
    	for(auto v : vs){
    		vector<int> c;
    		for(auto num : v){
    			int last = num;
    			while(last--) c.push_back(num);
    			permuteUnique(c);
    		}
    	}
    	auto it = st.upper_bound(n);
    	cout << *it;
    	return *it;

    }
    void dfs(int curNum,int start){
    	if(curNum > 8 or start > 8) return;
    	if(curNum < 8){
    		vs.push_back(temp);
    	}
    	for(int i = start; i <= 10; i++){
    		temp.push_back(i);
    		dfs(curNum + i, i + 1);
    		temp.pop_back();
    	}
    }


    void permuteUnique(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end()); // 1，对数组排序
        back(nums, used);
    }
    void back(const vector<int>& nums, vector<bool>& used) {
        if (path.size() == nums.size()) {
            // result.push_back(path);
            st.insert(getValue(path));
        }
        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;
            used[i] = true;
            path.push_back(nums[i]);
            back(nums, used);
            path.pop_back();
            used[i] = false;
            while (i+1 < nums.size() && nums[i] == nums[i+1]) i++; // 跳过后面重复数字
        }
    }
    int getValue(const vector<int> &path){
    	int ans  =0;
    	for(int i= 0; i < path.size(); i++){
    		ans = ans * 10 + path[i];
    	}
    	return ans;
    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	s.nextBeautifulNumber(10);
	/* code */


    return 0;
}