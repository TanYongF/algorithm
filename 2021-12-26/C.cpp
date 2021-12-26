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
    vector<long long> getDistances(vector<int>& arr) {
    	unordered_map<int, vector<ll>> mp;
    	unordered_map<int, vector<long long>> amp;
    	for(int i = 0; i <arr.size(); i++){
    		mp[arr[i]].push_back(i);
    		amp[arr[i]].push_back(i);
    	}
    	for(auto &it : amp){
    		for(int i = 1; i < it.second.size(); i++){
    			it.second[i] += it.second[i-1];
    		}
    	}
    	for(auto it : amp){
    		cout << it.first << ":";
    		for(auto v : it.second){
    			cout << v << " ";
    		}
    		cout << endl;
    	}
    	long long ans; 
    	vector<ll> ret;
    	for(int i = 0; i < arr.size(); i++){
    		ans = 0;
    		auto itIdx = lower_bound(mp[arr[i]].begin(), mp[arr[i]].end(), i);

    		int idx = itIdx - mp[arr[i]].begin();
    		// cout << idx << endl;
    		if(idx > 0) ans += 1LL * i * idx - amp[arr[i]][idx - 1];
    		// cout << ans << endl;
    		ans += amp[arr[i]].back() - amp[arr[i]][idx] - 1LL * (amp[arr[i]].size() - idx - 1) * i;
    		// cout << ans << endl;
    		ret.push_back(ans);
    		// cout << " .." << ans << endl;
    	}

    	return ret;
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	vector<int> te = {10,5,10,10}
	;
	s.getDistances(te);
	/* code */


    return 0;
}