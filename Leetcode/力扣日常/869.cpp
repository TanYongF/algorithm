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
	vector<int> pre;
	vector<int> temp;
	vector<int> hasVisted;
	bool flag = false;
	int size  =0 ;
    bool reorderedPowerOf2(int n) {
    	while(n){
    		size++;
    		pre.push_back((n % 10));
    		n /= 10;
    	}
    	hasVisted = vector<int>(size, false);
    	sort(pre.begin(), pre.end());
    	// for(auto it : pre) cout << it << " ";
    	// 	cout << endl;
    	back(pre, 0);
    	return flag;
    }
    void back(vector<int>& nums,  int curLen){
    	if(curLen == (int)nums.size()){
    		for(auto it : temp) cout << it << " " ; cout << endl;
    		flag = check(temp);
    		return;
    	}
    	for(int i = 0; i < size and (not flag); i++){
    		if(not hasVisted[i]){
    			temp.push_back(nums[i]);
    			hasVisted[i] = true;
    			back(nums, curLen + 1);
    			temp.pop_back();
    			hasVisted[i] = false;
    			while(i + 1 < size and nums[i] == nums[i+1]) i++;
    		}
    	}


    }
    bool check(vector<int> &nums){
    	ll num = 0;
    	// if(not nums[size-1]) return false;
    	for(int i = nums.size()-1; i >= 0; i--){
    		num = (num * 10) + nums[i];
    	}
    	// cout << num;
    	int bit= 0 ;
    	while(num!=0){
    		bit += (num & 1);
    		num >>= 1;
    		if(bit > 1) return false;
    	}
    	return true;
    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	// vector<int> test = 46;
	cout << s.reorderedPowerOf2(1000);
	// cout << s.check(test);
	/* code */


    return 0;
}