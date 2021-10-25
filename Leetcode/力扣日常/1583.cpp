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
#include <unordered_map>
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

    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
    	unordered_map<int,int> ps(1005);
		vector<unordered_map<int,int>> pre;
    	int ans = 0;
    	for(auto pair : pairs){
    		ps[pair[0]] = pair[1];
    		ps[pair[1]] = pair[0];
    	}
    	for(auto preference : preferences){
    		unordered_map<int,int> mp(505);
    		for(int i= 0; i < n-1; i++){
    			mp[preference[i]] = i;
    		}		
    		pre.push_back(mp);
    	}
    	int x,y,u,v;
    	for(int i = 0; i < n; i++){
    		x = i;
    		y = ps[x];
    		for(int j =0 ; j <n ;j++){
    			if(j == x || j == y) continue;
    			u = j;
    			v = ps[u];
    			// cout << pre[x][u] << pre[x][y] << pre[u][x] << pre[u][v] << endl; 
    			if(pre[x][u] < pre[x][y] && pre[u][x] < pre[u][v]){
    				ans++; 
    				// cout << x << y << u << v << endl;
    				// cout << "unhappy" << x << endl;
    			 	break;
    			}
    		}
    	}
    	return ans;

    }
};
int main(int argc, char * argv[]){
	// cout << 1 ;
	Solution s=  Solution();
// 	4
// [[1,3,2],[2,3,0],[1,0,3],[1,0,2]]
// [[2,1],[3,0]]
	vector<vector<int>> preferences = {{1,3,2},{2,3,0},{1,0,3},{1,0,2}};
	 vector<vector<int>> pairs = {{2,1},{3,0}};
	cout <<  s.unhappyFriends(4,preferences,pairs);

	/* code */


    return 0;
}