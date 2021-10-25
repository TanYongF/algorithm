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
    int ans = 0;
    bool hasVisted[16];
    int countArrangement(int n) {
        backtracing(1,n);
        return ans;
    }
    void backtracing(int curSize, int n){
        if(curSize == n+1){
            ans++;
            return;
        }
        for(int i = 1 ; i <= n ;i++){
            if(hasVisted[i]) continue;
            if(curSize % i == 0 || i % curSize == 0){
                hasVisted[i] = true;
                backtracing(curSize+1, n);
                hasVisted[i] = false;
            }
        }
    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	cout << s.countArrangement(3);
	/* code */


    return 0;
}