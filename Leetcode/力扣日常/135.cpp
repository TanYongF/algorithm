//https://leetcode-cn.com/problems/candy/
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
    int candy(vector<int>& ratings) {
        int ret= 1, inc = 1, dec = 0, pre= 1, len = ratings.size();
        for(int i = 1; i < len; i++){
            //如果右边的值大于左边的值,那么直接加1即可
            if(ratings[i] >= ratings[i-1]){
                dec = 0;
                //如果等于前一个,那么这个同学被分配e的个数为1
                pre = ratings[i] == ratings[i-1] ? 1 : pre + 1;
                //加上答案
                ret += pre;
                //递增序列长度等于最后一个元素的糖果数量
                inc = pre;
            }else{
                dec++;
                //如果递减序列等于前面最近的递增序列长度, 那么此时需要吧递增序列的最后一个同学给递减序列
                if(dec == inc) dec++;
                ret += dec;
                //将 pre重置为1
                pre = 1;
            }
        }
        return ret;

    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}