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

class SummaryRanges {
public:
	set<pair<int,int>> st; 
    SummaryRanges() {

    }
    
    void addNum(int val) {
    	int endd = val;
    	auto lower = st.lower_bound(make_pair(val,val));
    	auto upper = st.upper_bound(make_pair(val,val));
    	if(lower != st.end() and lower->first <= val and lower->second >= val) return;
    	if(upper != st.end() and upper->first == val + 1) {
            pair<int,int> ptoAdd= make_pair(val, upper->second);
            st.erase(upper);
    		st.insert(ptoAdd);
    		endd = ptoAdd.second;
    	}else{
    		st.insert(make_pair(val,val));
    	}
    	if(lower != st.end() and lower->second + 1 == val){
    		pair<int,int> ptoAdd = {lower->first, endd};
    		upper = lower;
            lower++;
    		st.erase(lower);
    		st.erase(upper);
    		st.insert(ptoAdd);
    	}
    }
    
    vector<vector<int>> getIntervals() {
    	vector<vector<int>> ans;
    	for(auto &it : st){
    		ans.push_back({it.first, it.second});
    	}
    	return ans;
    }
};

int main(int argc, char * argv[]){

	Solution s = SummaryRanges();
	/* code */


    return 0;
}