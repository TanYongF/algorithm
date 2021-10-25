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
    int minimumDifference(vector<int>& nums, int k) {
        int ans = INT_MAX;
        if(k== 1)return 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i <= nums.size()- k; i++){
            ans = min(ans, nums[i+k-1]-nums[i]);
        }
        return ans;

    }
};

int main(int argc, char * argv[]){

    Solution s = Solution();
    /* code */


    return 0;
}