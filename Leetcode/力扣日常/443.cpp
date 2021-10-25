//https://leetcode-cn.com/problems/string-compression/
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
	void wirteNum(vector<char>& chars, int Num, int &fromIndex){
		string num_s = to_string(Num);
		int len =  num_s.length();
		for(unsigned i = 0; i < len; ++i) {
			chars[fromIndex++] = num_s[i];
		}
	}
    int compress(vector<char>& chars) {
    	int len = chars.size();
    	char cur = ' ';
    	int curCharSize = 0, i = 0, j, curIndex = 0;
    	while(true){
	    	for(i = 0; i < len; i = j){
	    		cur = chars[i];
	    		chars[curIndex++] = cur;
	    		j = i + 1;
	    		curCharSize = 1;
	    		while(j < len && chars[j] == cur) {j++; curCharSize++;};
	    		if(curCharSize != 1) wirteNum(chars, curCharSize,  curIndex);
	    	}
	    	if(i == len) break;
    	}
    	// cout << " fa"
    	// for(auto it :chars) cout << it << " ";
    	return curIndex;
    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	string str = "aaabbbccc";
	vector<char> cs;
	for(int i = 0; i < str.length(); i++ ) cs.push_back(str[i]);
	cout << s.compress(cs);


    return 0;
}