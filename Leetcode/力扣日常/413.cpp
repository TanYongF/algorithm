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
	vector<int> res;
	int pred[5005];
    int numberOfArithmeticSlices(vector<int>& nums) {
    	int length = nums.size(),ans = 0, i ,j ;
    	if(length < 3) return 0;
    	nums.insert(nums.begin(), nums[0]);
    	printf("%x", pred[0]);
    	for( i = 1; i <= length; ++i) pred[i] = nums[i] - nums[i-1];
    	for(i = 2, j = i;  i <= length; i = j){
    		while(pred[j] == pred[i]){
    			j++;
    		}
    		int cursize = j - i+1;
    		ans += (cursize - 1) * (cursize - 2) /2;
    	}
    	return ans;
    }
};

int main(int argc, char * argv[]){
	vector<int> test;
	test.push_back(0);
	test.push_back(0);
	test.push_back(0);
	test.push_back(0);
	test.push_back(7);
	Solution s = Solution();
	s.numberOfArithmeticSlices(test);

	



    return 0;
}