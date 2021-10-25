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
	vector<vector<int>> ans;
	vector<vector<int>> obstacle;
	vector<vector<int>> terrain;
	bool hasVisted[101][101][101];
	int dx[4] = {0,1,0,-1};
	int dy[4] = {1,0,-1,0};
	int x, y ,m ,n, start_x, start_y;
    vector<vector<int>> bicycleYard(vector<int>& position, vector<vector<int>>& terrain, vector<vector<int>>& obstacle) {
    	this -> obstacle = obstacle;
    	this -> terrain = terrain;
    	m = terrain.size(), n = terrain[0].size();
    	start_x = position[0], start_y = position[1];
    	for(int i = 0; i <= 100; i++) for(int j = 0; j <= 100; j++) memset(hasVisted[i][j], 0, sizeof(hasVisted[i][j]));
    	hasVisted[start_x][start_y][1] = 1;
    	
    	dfs(1,start_x, start_y);

    	for(int i = 0; i < m ; i++)
   			for(int j = 0; j < n; j++){
   				for(int k = 0; k <= 100; k++) cout << hasVisted[i][j][k];
   				cout << endl;
   			}


    	for(int i = 0; i < m ; i++)
   			for(int j = 0; j < n; j ++)
   				if(i == start_x && j == start_y) continue;
   				else if(hasVisted[i][j][1]) ans.push_back({i,j});
   		return ans;
    }

    void dfs(int speed,int i, int j){
    	
    	for(int k = 0; k < 4 ; k++){
            int next_x = i + dx[k], next_y = j + dy[k];
            if(next_x < 0 || next_x > m-1 || next_y < 0 || next_y > n-1) continue;
            int temp = terrain[i][j] - terrain[next_x][next_y] - obstacle[next_x][next_y];
   
            if(speed + temp <= 0 || speed + temp > 100) continue;
            if(hasVisted[next_x][next_y][speed+temp]) continue;
            hasVisted[next_x][next_y][speed+temp] = true;
    		dfs(speed + temp, next_x, next_y);
    	}
    }
};



int main(int argc, char * argv[]){

	Solution s = Solution();
	vector<vector<int>> terrain = {{5,0}, {0,6}};
	vector<int> position = {1,1};
	vector<vector<int>> obstacle = {{0,6}, {7,0}};
	 s.bicycleYard(position, terrain, obstacle);
	/* code */


    return 0;
}