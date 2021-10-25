//https://leetcode-cn.com/problems/rabbits-in-forest/
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
    int numRabbits(vector<int>& answers) {
       	int ans =0;
       	unordered_map<int,int> mp;
       	for(auto answer : answers){
       		if(answer == 0) ans++;
       		else mp[answer]++;
       	}
        for(auto it : mp)ans += (it.first+1) * ceil(it.second / (it.first+1));
        return ans;
    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}