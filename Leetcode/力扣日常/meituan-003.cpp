#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <string>
#include <cstring>
#include <algorithm>
#include <unordered_map>
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

int T;
vector<pair<int,int>> vs;
int cmp(pair<int,int> p1 , pair<int,int> p2){
	return p1.first != p2.first ? (p1.first > p2.first) : (p1.second < p2.second); 
}
priority_queue<int, vector<int>, greater<int>> q;
int main(int argc, char * argv[]){
	int n, m, v, w;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> v >> w;
		vs.push_back(pair<int,int>(v + 2 * w, i));
	}
	sort(vs.begin(), vs.end(),cmp);
	int index= 0;
	while(m--){
		q.push(vs[index++].second);
	}
	while(!q.empty()){
		cout << q.top() << " ";
		q.pop();
	}
    return 0;
}