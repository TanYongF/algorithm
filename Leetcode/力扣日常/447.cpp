//https://leetcode-cn.com/problems/number-of-boomerangs
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
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int len = points.size();
        vector<unordered_map<int,int>> vs(len);
        for(int i = 0; i <len; i++){
            for(int j = 0; j < len; j++){
                
                vs[i][pow((points[i][1]-points[i][1]),2) + pow(points[i][0]-points[i][0],2)]++;
            }
        }
        int ans = 0;
        for(auto point : vs){
            for(auto it : point){
                ans += it.second * (it.second-1) / 2;
            }
        }
        return ans;

    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}