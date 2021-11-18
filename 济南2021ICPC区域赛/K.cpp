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
typedef pair<int,int> P;
const int MAXN = 1005;
int T;
int len;
vector<vector<int>> edge(101); 
vector<int> timeNeed(MAXN);
unordered_map<int, P> mp;
long long sumTime = 0;
int  curTime = 0;
bool hasVisted[101];
void dfs(int curNode){
	if(edge[curNode].size() == 0){
		sumTime += curTime;
		hasVisted[curNode] = true;
	} 
	if(not hasVisted[curNode]){
		sumTime += curTime, hasVisted[curNode] = true;
		
	} 
	curTime++;
	for(auto next : edge[curNode]){
 		dfs(next);
	}
	curTime++;
}
void slove(){
	cin >> len;
	edge = vector<vector<int>>(101); 
	memset(hasVisted, false, sizeof(hasVisted));
	// memset(edge, 0, sizeof(edge));
	hasVisted[1] = true;
	curTime = 0;
	sumTime = 0;
	for(int i = 0; i < len-1 ;i++){
		int from, to;	
		cin >> from >> to;
		edge[from].push_back(to);
	}
	dfs(1);
	// cout << sumTime << endl;
	printf("%.10f\n", 1.0 * sumTime / (len - 1));
}

int main(int argc, char * argv[]){

	cin >> T;
	while(T--){
		slove();
	}

    return 0;
}