#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <string>
#include <cstring>
#include <algorithm>
#include <unordered_map>
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
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        vector<unordered_map<long long ,int>> mps;
        int length = nums.size();
        long long ans = 0;
        for(int i = 1; i < length; i++){
            for(int j = 0; j < i; j++){
                long long d = 1.L * nums[i] - nums[j];
                auto it = mps[j].find(d);
                int cnt = it == mps[j].end() ? 0 :  mps[j][d];
                ans += cnt;
                mps[i][d] += mps[j][d] + 1; 
            }
        }
        return (int)ans;
    }};

int main(int argc, char * argv[]){


    return 0;
}


