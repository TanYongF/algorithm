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
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
    	vector<int> ans;
    	priority_queue<pair<long long,int>> pq;
    	unordered_map<int,int> mp;
    	set<int> st;
    	int maxx = INT_MIN;
    	for(int i = 0; i < k; i++) st.insert(i);
    	for(int i = 0; i < arrival.size(); i++){
    		
    		while((not pq.empty()) and  -1LL * pq.top().first <= arrival[i]){
    			st.insert(pq.top().second);
    			pq.pop();
    		}
    		int idx = arrival[i] % k;
    		if(st.empty()) continue;
    		auto it = st.lower_bound(idx);
    		if(it == st.end()) it = st.begin();
    		idx = *it;
    		mp[idx]++;
    	    pq.push({-1 * (load[i] + arrival[i]), idx});
    	    st.erase(idx);
    	    maxx = max(maxx, mp[idx]);
    	}
    	for(auto &it : mp){
    		if(it.second == maxx) ans.push_back(it.first);
    	}
    	return ans;
    }
};
int main(int argc, char * argv[]){


	// Solution s = Solution();
	/* code */
	priority_queue<int> pq;
	pq.push(1);
	pq.push(2);
	cout << pq.top();

    return 0;
}