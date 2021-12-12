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

class TopVotedCandidate {
public:
	unordered_map<int,int> mp;
	map<int,int, greater<int>> ans;
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
    	int len =  persons.size();
    	int mxNum = INT_MIN;
    	for(int i = 0; i < len; i++){
    		mp[persons[i]]++;
    		if(mp[persons[i]] >= mxNum){
    			ans[times[i]] = persons[i];
    			mxNum = mp[persons[i]]; 
    		}
    	}
    }
    
    int q(int t) {
    	auto it = ans.upper_bound(t); 
    	return it->second;
    }
};
int main(int argc, char * argv[]){

	// Solution s = Solution();
	/* code */


    return 0;
}