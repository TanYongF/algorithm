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
	int ret = INT_MAX;
	map<ll,int> mp;
	map<ll,int> mpCur;
	int goal;
	bool check(ll & num) {return (num >= 0 and num <= 1000) or num == goal;} 
    int minimumOperations(vector<int>& nums, int start, int goal) {
    	
        for(int i = 0; i <= 1000; i++) mp[i] = INT_MAX;
        mp[goal] = INT_MAX;
        mp[start] = 0;

    	bool has = true;
    	this->goal = goal;
    	vector<int> new1;
    	vector<int> old;
    	old.push_back(start);
    	while(mp[goal] == INT_MAX and  has ){
    		cout << 1 << endl;;
    		has = false;
    		mpCur = mp;
    		vector<int> new1;
	    	for(int i = 0; i < (int)nums.size(); i++){
	    		for(auto j : old){
	    			if(mp[j] == INT_MAX) continue;
                    ll add = j + nums[i];
                    ll del = j - nums[i];
                    ll xxo = j ^ nums[i];
                    if(check(add) and mp[add] == INT_MAX){
                    	new1.push_back(add);
                        mpCur[add] = mp[j] + 1; 
                        has = true;
                    } 
                    if(check(del) and mp[del] == INT_MAX){
                    	new1.push_back(del);
                        mpCur[del] = mp[j]+ 1;
                        has = true;
                    } 
                    if(check(xxo) and mp[xxo] ==INT_MAX){
                    	new1.push_back(xxo);
                        mpCur[xxo] = mp[j] + 1;
                        has = true;
                    } 
	    		}
	    	}
	    	old = new1;

	    	mp = mpCur;
	    	cout << mp.size() << endl;;
    	}
    	return mp[goal] == INT_MAX ? -1 : mp[goal];

    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	vector<int> nums1= {1,3};
	vector<int> nums = {-574938140,347713845,925500837,-396559946,-39213216,-696511059,-701862040,-547815957,-613314611,814380075,446824702,397447568,709912715,144793599,812441247,-59489753,857299470,360355629,85411951,-439873837,-477453514,-887964831,-914549223,633449658,452658511,657134722,1};
	int start= 6
, goal = 4;
	cout << s.minimumOperations(nums1, start, goal);
	/* code */


    return 0;
}