//https://leetcode-cn.com/problems/nim-game/
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <string>
#include <cstring>
#include <algorithm>
#include <unordered_set>
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
    int sg(int x){
    	unordered_set<int> S;  
    	for(int i = 1; i <= 3; i++){
    		if(x >= i) S.insert(sg(x-i));
    		else break;
    	}
    	for(int i =0; ; i++){
    		if (!S.count(i)) return i;
    	}

    }
    bool canWinNim(int n) {
    	for(int i =1; i <= n ;i++){
    		cout << i << " : " << sg(i) << endl;
    	}

    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	s.canWinNim(100);
	/* code */


    return 0;
}