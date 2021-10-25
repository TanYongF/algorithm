#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <string>
#include <cstring>
#include <algorithm>
#include <stack>
#include <unordered_set>
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
    vector<vector<int>> threeSum(vector<int>& nums) {
        int length = nums.size();
        unordered_set<int> sts;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < length; i++){
             sts.insert(nums[i]);
        }
        vector<vector<int>> res;
        for(int i = 0; i < length - 2; i++){
            if(i !=0 && nums[i-1] == nums[i]) continue;
            for(int j = i+1; j < length - 1; j++){
                if(j != i+1 && nums[j-1] == nums[j])  continue;
                int three = -(nums[i] + nums[j]);
                if(check(j+1, length-1, three, nums)){                    
                    vector<int> retItem;       
                    retItem.push_back(nums[i]);  
                    retItem.push_back(nums[j]);
                    retItem.push_back(three);
                    res.push_back(retItem);
                    break;
                }
            }
        }
        return res;
    }
    bool check(int L, int R, int num, vector<int> & nums){
        while(L <= R){
            int mid = (L + R) >> 1;
            if(nums[mid] == num) return true;
            else if(nums[mid]>num) check(L, mid-1, num,nums);
            else check(mid+1, R, num,nums);
        }
        return false;


    }
};
int main(int argc, char * argv[]){

    /* code */


    return 0;
}