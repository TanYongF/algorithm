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
    long long maxMatrixSum(vector<vector<int>>& matrix) {
    	long long  ans = 0;
    	long long  minN = INT_MAX;
    	int fusize = 0;
   		for(auto vs : matrix){
   			for(auto num : vs){
   				ans += abs(num);
   				minN = min(minN, abs((long long)num));
   				// if(num >= 0) {minN = min(minN, (long long)num);} 
   				if(num < 0) fusize++;
   			}
   		}
   		if(fusize%2 == 0) return ans;
   		else return ans - (2 * minN);

    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}