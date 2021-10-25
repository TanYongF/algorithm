//https://leetcode-cn.com/problems/spiral-matrix/
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
	vector<int> res;
	vector<vector<int>> matrix;
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
    	
    	int row = matrix.size(), col = matrix[0].size();
    	vector<int> item(col, -101);
    	matrix.insert(matrix.begin(), item);
    	matrix.insert(matrix.end(),item);
    	// for(auto it : matrix){
    	// 	it.insert(it.begin(), -101);
    	// 	it.insert(it.end(),-101);
    	// }
    	for(int i = 0; i <= row+1; i++){
    		matrix[i].insert(matrix[i].begin(), -101);
    		matrix[i].insert(matrix[i].end(), -101);
    	}
    	this->matrix = matrix;

    	dfs(1,1,1);
    	return res;
    }
    void dfs(int row, int col, int flag){
    	// cout <<  endl;
    	// for(auto i : matrix){
    	// 	for(auto j : i){
    	// 		printf("%5d",j);
    	// 	}
    	// 	cout << endl;
    	// }
    	res.push_back(matrix[row][col]);
    	matrix[row][col] = -101;
    	if(matrix[row+1][col] == -101 && matrix[row-1][col] == -101 && matrix[row][col-1] == -101&& matrix[row][col+1] == -101) return;
    	if(flag == 1){
    		if(matrix[row][col+1] != -101) dfs(row, col+1, 1);
    		else dfs(row+1, col, 2);
    	}else if(flag == 2){
    		if(matrix[row+1][col] != -101) dfs(row+1, col, 2);
    		else dfs(row, col-1, 3);
    	}else if(flag == 3){
    		if(matrix[row][col-1] != -101) dfs(row, col-1, 3);
    		else dfs(row-1, col, 4);
    	}else if(flag == 4){
    		if(matrix[row-1][col] != -101) dfs(row-1, col, 4);
    		else dfs(row, col+1, 1);
    	}
    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	vector<vector<int>> matrix ={{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25}};
	s.spiralOrder(matrix);
	for(auto it : s.res) {
		cout << it << " ";
	}
	/* code */


    return 0;
}