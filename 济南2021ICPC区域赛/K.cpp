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
vector<vector<int>> edge(MAXN);
vector<int> timeNeed(MAXN);
unordered_map<int, P> mp;
int getChildNum(int val){
	if(edge[val].size() == 0){
		mp[val] = {0,0};
		return 1;
	} 
	mp[val] = {0,0};
	mp[val].first = getChildNum(edge[val][0]);
	if(edge[val].size() == 2) mp[val].second = getChildNum(edge[val][1]);
}
int curTime = 0;
int hasVisited = 0;
void getTime(int val){
	if(edge[val].size() == 0){
		timeNeed[val] = curTime;
		hasVisited++;
		return; 
	}
	timeNeed[val] = curTime;
	curTime++;
	if((not mp[val].first) and (not mp[val].second)){
		if(mp[val].)
	}
	if(not mp[val].first) getTime(edge[val][0]);

}

void slove(){
	cin >> len;
	for(int i = 0; i < len ;i++){
		int from, to;	
		cin >> from >> to;
		edge[from].push_back(to);
	}
	getChildNum(1);
	getTime(1);

}

int main(int argc, char * argv[]){

	cin >> T;
	while(T--){
		slove();
		cin >> len;
		// for()
		

	}


    return 0;
}