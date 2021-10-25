//https://leetcode-cn.com/problems/search-a-2d-matrix/
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <string>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <climits>
#include <vector>
#include <iostream>
#include <list>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    	int row = matrix.size(), col = matrix[0].size();
    	int i = row-1, j = 0;
    	while(matrix[i][j] > target) i--;
    	if(i < 0) return false;
    	for(; j < col; j++){
    		if(matrix[i][j] == target) return true;
    		if(matrix[i][j] < target) return false;
    	}
    	return true;
    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}