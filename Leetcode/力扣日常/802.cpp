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
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
   		int length = graph.size();
		vector<vector<int>> dgraph(length);
		vector<int> inDegree(length);
		vector<int> res;
		for(unsigned i = 0; i < length; ++i) {
			for(auto x : graph[i]){
				dgraph[x].push_back(i);
			}
			inDegree[i] =  graph[i].size(); 
		}

		queue<int> q;
		for(unsigned i = 0; i < length; ++i) {
			if(inDegree[i] == 0){
				q.push(i);
			}
		}

		while(!q.empty()){
			int cur = q.front();
			for(auto next : dgraph[cur]){
				inDegree[next]--;
				if(inDegree[next] == 0) {
					q.push(next);
					// res.push_back(next);
				}
			}
			q.pop();
		}
		for(int i =0; i < length; i++){
			if(inDegree[i] == 0)
				res.push_back(i);
		}
		return res;
    }
};



int main(int argc, char * argv[]){

	/* code */


    return 0;
}