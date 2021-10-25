//https://leetcode-cn.com/problems/ipo/
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

// struct cmp{
// 	bool operator ()(const pair<int,int> &p1, const pair<int,int> &p2){
// 		return  p1.second > p2.second;
// 	}
// };
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
    	int len = profits.size(), ans = w;
    	vector<pair<int,int>> arr(len);
    	multiset<int, less<int>> st;
    	int curIdx = 0;
    	for(int i = 0 ; i < len; i++)	arr.push_back({capital[i],profits[i]});
    	sort(arr.begin(), arr.end());
    	while(k--){
    		if(st.size()==0) break;
    		while(curIdx < len && arr[curIdx].first <= ans) {
    		    st.insert(arr[curIdx].second);
    		    curIdx++;
    		}
    		ans += *st.begin();
    	}
    	return ans;


    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}