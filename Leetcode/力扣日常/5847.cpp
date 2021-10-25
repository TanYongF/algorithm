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
	int x[4] = {0, -1, 0, 1};
	int y[4] = {1, 0, -1, 0};
	bool hasVisted[310][310];
	int target_x = INT_MIN, target_y =INT_MIN;
	void dfs(int xx, int yy){
		for(int i = 0; i < 4; i++){
			if(!hasVisted[xx+x[i]][yy+y[i]]){
				target_x = max(target_x, xx+x[i]);
				target_y = max(target_y, yy+y[i]);
				hasVisted[xx+x[i]][yy+y[i]]= true;
				dfs(xx+x[i], yy+y[i]);
			}
		}
	}
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
    	int m = land.size(), n = land[0].size();
		vector<int> temp(n+2);
		vector<vector<int>>  res;
		land.insert(land.begin(), temp);
		land.insert(land.end(), temp); 
		for(int i = 1; i <= m; i++){
			land[i].insert(land[i].begin(), 0);
			land[i].insert(land[i].end(), 0);
		}  
 
	// for(auto v : land){
	// 	for(auto vv : v){
	// 		cout << vv  << " " ;
	// 	}
	// 	cout << endl;
	// }
	memset(hasVisted, false, sizeof(hasVisted));
	for(int i = 0; i <= m+1; i++)
    		for(int j = 0; j <= n+1; j++)
    			if(land[i][j] == 0) hasVisted[i][j] = true; 
    	
    	for(int i = 0; i <= m+1; i++){
    		for(int j = 0; j <= n+1; j++){
    			if(land[i][j] == 0) hasVisted[i][j] = true;
    			if(land[i][j] == 1 && !hasVisted[i][j]){
    				target_x = i, target_y =j;
    				dfs(i, j);
    				vector<int> item(4);
    				item[0] = i-1;
    				item[1] = j-1;
    				item[2] = target_x-1;
    				item[3] = target_y-1;
    			    res.push_back(item);
    			}
    		}
    	}
    	return res;
    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	 vector<vector<int>>  t= {{1,0,0},{0,1,1},{0,1,1}};
	vector<vector<int>> ans = s.findFarmland(t);
	for(auto v : ans){
		for(auto vv : v){
			cout << vv  << " " ;
		}
		cout << endl;
	}
    return 0;
}