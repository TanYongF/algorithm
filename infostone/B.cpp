#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;

// 图
vector<vector<int>> g(101, vector<int>());
// 入度
vector<int> inDegree(101, 0);
int n;
// 处理输入
vector<pair<int,int>> transfer(string s, char tag){
	int i = 0, j = 0, n = s.size();
	vector<int> nums;
	while(j < n){
		i = j;
		while(i < n and (s[i] > '9' or s[i] < '0')) i++;
		j = i;
		while(j < n and s[j] <= '9' and s[j] >= '0')j++;
		if(j - i > 0) nums.push_back(stoi(s.substr(i, j - i)));
	}
	vector<pair<int,int>> ret;
	for(int i = 0; i < nums.size(); i+=2){
		ret.push_back({nums[i], nums[i+1]});
	}
	return ret;
}


//拓扑排序
bool check(vector<vector<int>> g){
	queue<int> q;
	int count = 0;
	for(int i = 0; i < n; i++){
		if(inDegree[i] == 0) {
			q.push(i);
			count++;
		}
 	}
 	while(not q.empty()){
 		int cur = q.front();
 		q.pop();
 		for(auto next : g[cur]){
 			inDegree[next]--;
 			if(inDegree[next] == 0){
 				q.push(next);
 				count++;
 			}
 		}
 	}
 	return count == n;
}




int main(int argc, char * argv[]){
	string s;

	cin >> n >> s;
	auto dependencies = transfer(s, ',');

	//build graph
	for(auto &[src, dest] : dependencies){
		g[src].push_back(dest);
		inDegree[dest]++;
	}

	cout << (check(g) ? "true" : "false");
    return 0;
}