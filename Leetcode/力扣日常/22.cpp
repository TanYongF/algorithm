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
    vector<string> res;
    string item;
    vector<string> generateParenthesis(int n) {
        dfs(0,0,n);
        return res;
       
    }
    void dfs(int leftSize, int rightSize,int n){
    	if(rightSize > leftSize || leftSize > n) return;
    	if(rightSize == n) res.push_back(string(item));
    	item.push_back('(');
    	dfs(leftSize + 1, rightSize, n);
    	item.pop_back();

    	item.push_back(')');
    	dfs(leftSize, rightSize+1, n);
    	item.pop_back();
    } 
};
int main(int argc, char * argv[]){
	 Solution s = Solution();
	 std::vector<string> v =  s.generateParenthesis(8);
	 for(auto str : v) {
	 	cout << str << endl;
	 }

	/* code */


    return 0;
}