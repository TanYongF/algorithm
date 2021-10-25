
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
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;


class Solution {
public:
    int tribonacci(int n) {
        int res[38];
        res[0] =0 ;
        res[1] = 1;
        res[2] = 2;
        for(int i = 3; i < 38; i++){
            res[i] = res[i-1] + res[i-2] + res[i-3];
        }
        return res[n];

    }
};
int main(){
    Solution s = Solution();
    cout << s.tribonacci(37);

    return 0;
}