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
    int minTimeToType(string word) {
    	int ans = 0;
    	int len = word.length();
    	word.insert(word.begin(), 'a');
    	for(int i = 1; i <= len; i++){
    		int a = (int)(word[i]-'a'+1) ;
    		int b = (int)(word[i-1]-'a'+1);
    		int item = min(abs(a-b), b + 26 - a);
    	    item = min(item, a + 26 - b);
    		ans += item;
    	}
    	return  ans + len;
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	cout << s.minTimeToType("z");
	/* code */


    return 0;
}