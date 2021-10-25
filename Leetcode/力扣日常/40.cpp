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
    vector<vector<int>> res;
    vector<int> resItem;
    int length ;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        length = candidates.size();
        sort(candidates.begin(), candidates.end());

        // for(unsigned i = 0; i < length; ++i) {
        //     cout << candidates[i] << " ";
        // }

        backTracing(target, candidates, 0,0);
        return res;
    }

    void backTracing(int target, vector<int>& candidates, int curIndex,int curSum){
        if(curSum == target){
            res.push_back(vector<int>(resItem));
            return;
        }else if(curSum > target){
            return;
        }
        for(int i = curIndex; i < length && candidates[i] + curSum <= target; i++){
            if( i > curIndex &&  candidates[i] == candidates[i-1]) continue;
            curSum += candidates[i];
            resItem.push_back(candidates[i]);
            backTracing(target, candidates, curIndex + 1, curSum + candidates[i]);
            curSum -= candidates[i];
            resItem.pop_back();
        }

    }
};

int main(int argc, char * argv[]){

    vector<int> t;
    t.push_back(10);
    t.push_back(1);
    t.push_back(2);
    t.push_back(7);
    t.push_back(6);
    t.push_back(1);
    t.push_back(5);
    Solution s = Solution();
    s.combinationSum2(t,8);
    /* code */


    return 0;
}

