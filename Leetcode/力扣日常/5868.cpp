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

int gcd(int x, int y){
	if(y == 0) return x;
	return gcd(y, x%y);
}
class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
    	map<pair<int,int>,int> mp;

    	for(auto rectangle : rectangles){
    		int g = gcd(rectangle[0], rectangle[1]);
    		mp[{rectangle[0]/g, rectangle[1]/g}]++;
    	}
    	long long ans = 0;
    	for(auto it : mp){
    		if(it.second == 1) continue;
    		ans += 1.0L * (it.second) * (it.second-1) /2;
    	}
    	return ans;
    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	vector<vector<int>> rectangles = {{4,8},{3,6},{10,20},{15,30}};
	cout << s.interchangeableRectangles(rectangles);
    return 0;
}