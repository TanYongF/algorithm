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
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ret;
        vector<int> dots;
        int last = INT_MIN, diff[10010];
        memset(diff, 0, sizeof(diff));
        for(auto interval : intervals){
            if(interval[0] == interval[1]) {dots.push_back(interval[0]); continue;}
        	last = max(last, interval[1]);
        	diff[interval[0]]++;
        	diff[interval[1]]--;
        }
        
        for(int i = 1; i <= last+1; i++) diff[i] += diff[i-1];
        for(auto dot : dots){
            if(diff[dot] != 0) continue;
            else ret.push_back({dot,dot});
            // for(int i = 0; i <= last; i++) cout << diff[i];
        }
        for(int i = 0, j = 0; i <= last; ){
            if(diff[i]==0) {i++; continue;}
            j = i;
        	while(diff[j] != 0) j++;
        	ret.push_back({i,j});
            i = j;
            // cout <<i;
        }

        return ret;

    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	vector<vector<int>> test = {{1,4},{5,6}};
    s.merge(test);
	/* code */


    return 0;
}