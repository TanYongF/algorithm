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
    int threeSumClosest(vector<int>& nums, int target) {
    	int length = nums.size();
    	sort(nums.begin(), nums.end());
    	int res = 1e7;
    	for(unsigned i = 1; i < length-1; ++i) {
    		int j = 0 , k = length-1;
    		int cur = target - nums[i];
    		while(j != i && k != i){
    			int jandk = nums[k] + nums[j]; 
    			if(nums[k] + nums[j] == cur) return 0; 
    			else if(nums[k] + nums[j] > cur) {
    				k--; 
    			} 
 				else{
 					j++;
				}
				if(abs(jandk + nums[i] - target) < abs(res - target)){
					res = jandk + nums[i];
				}			
    		}
    	}
    	return res;
    }
};
 
int main(int argc, char * argv[]){


	/* code */


    return 0;
}