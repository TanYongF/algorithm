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
#include <unordered_map>
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
    bool circularArrayLoop(vector<int>& nums) {
        const int length = nums.size();
        //俵济数组
        vector<int> isVisted(length);
        for(int i = 0; i < length; i++){
            if(isVisted[i] == 1) continue;
            unordered_map<int,int> mp;
            int prepos = i;
            while(1){
                int nextpos = ((nums[i] + prepos)%length + length) % length;
                //如果相邻两个节点互相形成环 或者是 两个正负情况不太一样 就直接返回。
                if( prepos == nextpos || nums[nextpos] * nums[prepos] < 0) break;
                //这里我们用mp来判断 nextpos是否已经遍历过，如果已经遍历过，那么直接返回true就可以。
                if(mp.count(nextpos)){
                    return true;
                }
                //这个节点已经遍历过放入map 并 标记为已经访问过
                mp[prepos] = nums[prepos];
                isVisted[prepos] = 1;
                prepos = nextpos;
            }
        }
        return false;
    }
};

int main(int argc, char * argv[]){

	/* code */


    return 0;
}