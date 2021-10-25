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
#include <list>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;

class Solution {
public:

    vector<int> findOriginalArray(vector<int>& changed) {
    	vector<int> ans;
    	int len  = changed.size();
    	if(len % 2 != 0) return ans;
    	// bool hasVisted[len];
    	unordered_map<int,int> mp;
    	for(auto chang : changed) mp[chang]++;
    	memset(hasVisted, false, sizeof(hasVisted));
    	sort(changed.begin(), changed.end());
    	for(int i = 0 ; i < len; i++){
    		if(mp[changed[i]] == 0) continue;
    		if(mp[2 * changed[i]] == 0){
    			vector<int> ans;
    			return ans;
    		}else{
    			ans.push_back(changed[i]);
    			mp[2 * changed[i]]--;
    			mp[changed[i]]--;
    		}
    	}
    	for(auto ss : ans) cout << ss << " ";
    	return ans;
    }
};

int main(int argc, char * argv[]){

vector<int> a = {6,12,6,12};
	Solution s = Solution();
	s.findOriginalArray(a);
	/* code */


    return 0;
}