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
	void reverse(string &s, int from, int to){
		while(from < to){
			swap(s[from],s[to]);
			from++;
			to--;
		}
	}
    string reverseStr(string s, int k) {
    	int len = s.length();
        s.insert(s.begin(), ' ');
        for(int i = 1; i <= len; i+=2*k){
        	if(i + k -1 > len) reverse(s,i, len);
        	else reverse(s,i, i + k -1);
        }

        return s.substr(1,len);
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	cout << s.reverseStr("a",2);
	/* code */


    return 0;
}