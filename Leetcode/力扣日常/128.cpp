#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <string>
#include <cstring>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <ctime>
#include <climits>
#include <vector>
#include <iostream>
#include <fstream>
#include <list>
#include <iomanip>
#include <numeric>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;

class Solution {
public:
	priority_queue<int, vector<int>,greater<int>> pq;
    int longestConsecutive(vector<int>& nums) {
    	int len = nums.size();
    	if(len == 0) return 0;
    	for(int i = 0 ; i < len; i++) pq.push(nums[i]);
    	// for(auto it : pq) cout << it << " " ;
    	// cout << pq[0];
    	int index = 0;
    	while(!pq.empty()){
    		int num = pq.top();
    		pq.pop();
    		if(index != 0 && num == nums[index-1]) continue; 
    		nums[index++] = num;
    	}

    	// for(auto it : nums) cout << it << " " ;

    	int ans = 1, cur, i = 0;
    	while(i < len-1){
    		// cout << i << " " << endl;
    		cur = 1;
    		int j = i + 1;
    		int L = nums[j] - nums[i];
    		if(L != 1) { i++; continue;}
    		while(j < len && nums[j] - nums[j-1] == 1){
    			cur++;
    			j++;
    		}
    		ans = max(ans,cur);
    		i = j;
    	}
    	return ans;
    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	vector<int> v = {1,2,0,1};
	cout << s.longestConsecutive(v);
	/* code */

    return 0;
}