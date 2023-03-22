#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;

int T;
const int MAXN = 1e5 + 10;
int from[MAXN], to[MAXN], n;
int main(int argc, char * argv[]){
	map<int, int> mp;
	cin >> n;
	for(int i = 0; i < n; i++) cin >> from[i];
	for(int i = 0; i < n; i++) cin >> to[i];
	for(int i = 0; i < n; i++){
		mp[from[i]]++;
		mp[to[i] + 1]--;
	}
	int max_count = 0;
	int count = 0;
	vector<pair<int,int>> p;
	for(auto it : mp){
		count += it.second;
		max_count = max(count, max_count);
		p.push_back({it.first, count});
	}
	int ans = 0;
	for(int i = 0; i < p.size(); i++){
		if(p[i].second == max_count){
			ans += p[i+1].first - p[i].first;
		}
	}
	cout << max_count << " " << ans;
    return 0;
}