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
    int sumOddLengthSubarrays(vector<int>& arr) {
    	int len = arr.size(), ans = 0;
    	int preodd, lastodd, preven, lasteven;
    	for(int i =0; i < len; i++){
    		int left = i + i, right = len - i;
    		preodd = left/2 , lastodd = right/2;
    		preven =(left+1)/2, lasteven= (right+1)/2;
    		ans += (preodd*lastodd + preven*lasteven)*arr[i]; 
    	}
    	return ans;
    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}