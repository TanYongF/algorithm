//https://leetcode-cn.com/problems/corporate-flight-bookings/
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
	vector<int> a;
	int n;
	int lowbit(int x){
		return x & -x;
	}
	void add(int x, int k){
		while(x <= n){
			a[x] += k;
			x += lowbit(x);
		}
	}
	int getsum(int x){
		int ans = 0;
		for(int i = x; i > 0; i -= lowbit(i)) ans += a[i];
		return ans;
	}

    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
    	this -> n = n;
    	vector<int> ret;
    	a = vector<int>(n+2);
    	for(auto booking : bookings){
    		add(booking[0], booking[2]);
    		add(booking[1]+1, -booking[2]);
    	}
    	for(int i = 1; i <= n; i++)	ret.push_back(getsum(i));
    	return ret;
    }
};

//前缀和
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
    	vector<int> a(n+2, 0);
    	for(auto booking : bookings){
    		a[booking[0]] = booking[2];
    		a[booking[1]+1] -= booking[2];
    	}
    	for(int i = 1; i <= n; i++){
    		a[i] += a[i-1];
    	}
    	a.erase(a.begin());
    	a.erase(a.end()-1);
    	return a;


    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}