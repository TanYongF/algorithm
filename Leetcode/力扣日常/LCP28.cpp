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
    int purchasePlans(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        long long ret = 0;
        int mod = 1e9+7;
        for(int i = 0 ; i< nums.size()-1; i++){
            ret = (ret + bsearch(i, nums, target) - i) % mod; 
        }
        return ret;


    }
    int bsearch(int fromIndex,vector<int>& nums, int target){
        int num = nums[fromIndex];
        int L = fromIndex + 1, R = nums.size();
        int ans = fromIndex;
        while(L <= R){
            int mid = (L + R) >> 1;
            if(num + nums[mid] <= target){
                L = mid + 1;
                ans = mid;
            }else R = mid - 1;
        }
        cout << num << " "
        << fromIndex << " " << ans << endl;
        return ans;

    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	std::vector<int> v = {2,2,1,9};
	cout << s.purchasePlans(v, 20);
	/* code */


    return 0;
}