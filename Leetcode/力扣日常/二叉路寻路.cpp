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
#include <vector>
#include <fstream>
#include <list>
#include <iomanip>
#include <numeric>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s) memset(s, 0, sizeof(s))
const int inf = 0x3f3f3f3f;



class Solution {

public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> res ;
        res.push_back(label);
        int maxdep = 1;
        int maxval = 1;
        while(maxval  <= label){
            maxval = maxval << 1;
            maxdep++;
        }
        maxdep--;
        int remain, dlabel;
        for(unsigned i = maxdep; i > 1; --i) {
            if(i % 2 == 1){
                 remain = label -pow(2,i-1);
                 dlabel = pow(2, i)- 1 - remain;
            }else{
                remain = pow(2, i) -1 - label;
                dlabel = remain + pow(2, i-1);
            }
             label = dlabel >> 1;
             res.insert(res.begin(), label);
        }
        // cout << maxdep << endl;

        return res;
    }
};
int main(){
    Solution s = Solution();
    vector<int> res = s.pathInZigZagTree(1);
    for(auto it : res){
        cout << it << " ";
    }
    cout <<  endl;
}