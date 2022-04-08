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
bool cmp(pair<int,int> p1, pair<int,int> p2){
	if(p1.first == p2.first) return false;
	else return  p1.first <= p2.first;
}
class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
    	vector<pair<int,int>> ans;
    	for(auto &num : nums){
    		string cn = to_string(num);
    		for(auto &ch : cn){
    			ch = mapping[ch-'0'] + '0';
    		}
    		ans.push_back({stoi(cn), num});
    	}
    	sort(ans.begin(), ans.end(), cmp);
    	vector<int> ret;
    	for(auto &p : ans) ret.push_back(p.second); 
    	return ret;
        
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}