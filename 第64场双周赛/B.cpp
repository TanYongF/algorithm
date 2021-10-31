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

int cmp(vector<int> event1, vector<int> event2){
	return event1[0] < event2[0];
}
class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
    	int len = events.size();
      map<int,int> mp;
    	sort(events.begin(), events.end(), cmp);

      mp[events[len-1][0]] = events[len-1][2];
      for(int i = len-2; i >=0; --i){
        mp[events[i][0]] = max(events[len-1][2], mp[events[i+1][0]]);
      }
      // for(auto it : mp) cout << it.first << " " << it.second << endl;


// cout << endl;
    	// lastMax[len-1] = events[len-1][2];
    	// for(auto event : events){ cout << event[0] << " " << event[1] << " " << event[2] <<  endl;}
    	// for(int i = len - 2; i >=0 ; --i){
    	// 	lastMax[i] = max(events[i][2], lastMax[i+1]);
    	// } 
    	// for(int i =0 ;i < len ;i++) cout << lastMax[i] << " ";
    	// 	cout << endl;
    	int ans = INT_MIN;
    	for(int i =0; i < len; i++){
        auto it = mp.upper_bound(events[i][1]);
        if(it != mp.end()){
          ans = max(ans, events[i][2] + it->second);
        } else{
          ans = max(ans, events[i][2]);
        }
    		// ans = max(ans, events[i][2] + lastMax[events[i][1]+1]);
    	}
    	return ans;
        
    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	vector<vector<int>> test = {{66,97,90},{98,98,68},{38,49,63},{91,100,42},{92,100,22},{1,77,50},{64,72,97}};
	cout << s.maxTwoEvents(test);
	/* code */


    return 0;
}