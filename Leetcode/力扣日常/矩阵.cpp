#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;

int T;
int main(int argc, char * argv[]){
	int n = 0;
	cin >> n;
	set<int> infected;
	int isConn, infect;
	vector<unordered_set<int>> conn = vector<unordered_set<int>>(n);
	string row;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> row;
			// cout << row << endl;
			isConn = row[0] - '0';
			// isConn = row[j] - '0';
			if(isConn and i != j) {
				conn[i].insert(j);
				conn[j].insert(i);
			}
		}
	}
	// for(auto it : conn){
	// 	for(auto tmp : it) cout << tmp << " ";
	// 		cout << endl;
	// }
	cin >> infect;
	// bfs
	queue<int> q;
	q.push(infect);
	infected.insert(infect);
	while(not q.empty()){
		int infectPeople = q.front();
		q.pop();
		for(auto &connPeople : conn[infectPeople]){
			if(not infected.count(connPeople)){
				infected.insert(connPeople);
				q.push(connPeople);
			}
		}
	}
	string ans = "[";
	for(auto p : infected){
		ans += to_string(p) + ", ";
	}
	ans.pop_back();
	ans.pop_back();
	ans.push_back(']');
	cout << ans;
    return 0;
}