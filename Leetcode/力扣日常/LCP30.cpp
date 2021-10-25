// /https://leetcode-cn.com/problems/p0NxJO/
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
    int magicTower(vector<int>& nums) {
    	priority_queue<int> pq;
    	long long sum = 0;
    	int ans = 0;
    	for(auto num : nums) sum += num;
    	if(sum<0) return -1;
    	long long curHeal = 0;
    	for(auto num : nums){
    		if(num < 0) pq.push(-num);
    		curHeal += num;
    		if(curHeal < 0){
    			ans++;
    			curHeal += pq.top();
    			pq.pop();
    		}
    	}
    	return ans;

    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */
	std::vector<int> v = {100,100,100,-250,-60,-140,-50,-50,100,150};
	cout << s.magicTower(v);

    return 0;
}