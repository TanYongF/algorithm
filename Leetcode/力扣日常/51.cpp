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
	vector<vector<string>> res;
	vector<string> item;
	string str;
	unordered_map<int,bool> hasXYVisted, hasColVisted,hasXVisted,hasYVisted;
    vector<vector<string>> solveNQueens(int n) {
    	hasXYVisted = unordered_map<int,bool>(2*n+1);
    	hasColVisted = unordered_map<int,bool>(n+1);
    	hasXVisted = unordered_map<int,bool>(2*n+1);
    	hasYVisted = unordered_map<int,bool>(2*n+1);
    	for(int i = 1; i <= n; i++) str += '.';
    	backtrack(1,n);
    	return res;
    }
    void backtrack(int curRow,int n){
    	if(curRow == n+1){
    		vector<string> resItem = vector<string>(item);
    		res.push_back(resItem);
    	}
    	for(int i = 1; i <= n; i++){
    		if(hasXYVisted[curRow + i] || hasColVisted[i] || hasXVisted[curRow - i] || hasYVisted[i - curRow]) continue; 
    		hasColVisted[i] = true;
    		hasXYVisted[curRow + i] = true;
    		hasXVisted[curRow - i] = true;
    		hasYVisted[i - curRow]  = true;
    		string temp = string(str);
    		temp[i-1] = 'Q';
    		item.push_back(temp);
    		backtrack(curRow+1, n);
    		item.pop_back();
    		hasColVisted[i] = false;
    		hasXVisted[curRow - i] = false;
    		hasXYVisted[curRow + i] = false;
    		hasYVisted[i - curRow]  = false;    		
    	}

    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	vector<vector<string>> res = s.solveNQueens(4);
	for(auto vs : res){
		for(auto item : vs){
			cout << item << " " ;
		}
		cout << endl;
	}
	/* code */


    return 0;
}